#include <errno.h>
#include <fcntl.h>
#include <linux/input.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "rt_nonfinite.h"
#include "springMassTakeStep.h"
#include "springMassTakeStep_initialize.h"
#include "springMassTakeStep_terminate.h"
#include "springMass_main.h"

int getDevice(char* argv[]) {
    int fd;

    /* Open the specified device */
    do {
        fd = open(argv[1], O_RDONLY);
    } while (fd == -1 && errno == EINTR);

    if (fd == -1) {
        fprintf(stderr, "%s: %s.\n", argv[1], strerror(errno));
        return 1;
    }

    fflush(stderr);

    return fd;
}

void dispMass(double xi, double xf) {
    int i;
    double winWidthMax;
    winWidthMax = 60;
    /* Set initial spring length to .5*winWidthMax characters */
    xf *= winWidthMax / 2;
    xi *= winWidthMax / 2;

    fprintf(stdout, "|");
    for (i = 0; i <= xf; i++) {
        fprintf(stdout, "-");
    }
    fprintf(stdout, "###\n");
}

int main(int argc, char* argv[]) {
    struct input_event ev;
    int fd, doSim;
    int flags;
    ssize_t n;
    double xi, vi, ti, dt, g, xf, vf, s;

    /* Set initial conditions for simulation */
    xi = 0.5;  /* initial position */
    vi = 0;    /* initial velocity */
    ti = 0;    /* initial time */
    dt = 0.01; /* time step */
    g = 0;     /* initial "gravity" force */
    s = 30;    /* sensitivity to mouse movement */

    /* Check that mouse device is provided */
    if (argc != 2) {
        fprintf(stderr, "Usage: %s /dev/input/eventN\n", argv[0]);
        fprintf(stderr, "where N=0,1,2, etc. See documentation.\n");
        return 0;
    }

    fd = getDevice(argv);

    /* Enable nonblocking i/o */
    flags = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flags | O_NONBLOCK);

    /* Intialize generated function code */
    springMassTakeStep_initialize();

    /* Run simulation loop */
    doSim = 1;
    while (doSim) {
        /* Slow down the iterations to loosely mimic real-time speed.
         * Iteration time takes roughly .001 seconds on a 3 B+;
         * usleep(9000) adds a .009 second delay;
         * these sum up to mimic a .01 second delay in execution time,
         * mimicking a .01 second delay dt time */
        usleep(9000);

        /* Read device event */
        n = read(fd, &ev, sizeof ev);
        /* Use a change in relative mouse position event to apply a force */
        if (ev.type == EV_REL) {
            /* Coordinate sign of force to direction of mouse movement */
            if (ev.code == 0) {
                if (ev.value > 0) {
                    /* Attenuate mouse acceleration by a logarithmic scale */
                    g = log(2.73 * (double)abs(ev.value)) * s;
                } else if (ev.value < 0)
                    g = -log(2.73 * (double)abs(ev.value)) * s;
            }
        }
        /* Do nothing if event type is a synchronization event */
        else if (ev.type == EV_SYN) {
        }

        /* Simulate across one time step */
        springMassTakeStep(xi, vi, ti, dt, g, &xf, &vf);

        /* Display the current position */
        dispMass(xi, xf);

        /* Reset "gravity" force and step state variables */
        g = 0;
        xi = xf;
        vi = vf;
        ti = ti + dt;
    }

    /* Terminate generated code and close event file */
    springMassTakeStep_terminate();
    close(fd);
    return 0;
}
