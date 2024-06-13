/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Learner.c
 *
 * Code generation for function 'Learner'
 *
 */

/* Include files */
#include "Learner.h"
#include "RegressionModel.h"
#include "myInitialModelIncrLearn_types.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include <string.h>

#include <stdio.h>
#include "debug.h"


/* Function Definitions */
// C:\Program Files\MATLAB\R2022a\toolbox\stats\incremental\+incremental\+impl\SGDImpl.m
// function this = fitLinear(this,X,Y,W,WisRaw,obsInRows,~,stream) 

// result is defferent between matlab and this codegen code.
/*
matlab

K>> IncrementalMdl.Beta

ans =

   -0.4402
   -0.2569
   -0.0662
    0.0264
    0.1518
    0.3210
    0.4856
    0.5569
    0.4484
    0.2338
    0.0415
   -0.1009
   -0.0854
   -0.0113
    0.1326
   -0.0375
    1.0292
    0.2708
   -0.4946
   -0.4823


K>>    

Codegen code

this->Impl.Beta[0] = -0.4522
this->Impl.Beta[1] = -0.2680
this->Impl.Beta[2] = -0.0752
this->Impl.Beta[3] = 0.0314
this->Impl.Beta[4] = 0.1390
this->Impl.Beta[5] = 0.3095
this->Impl.Beta[6] = 0.4762
this->Impl.Beta[7] = 0.5615
this->Impl.Beta[8] = 0.4352
this->Impl.Beta[9] = 0.2218
this->Impl.Beta[10] = 0.0316
this->Impl.Beta[11] = -0.0969
this->Impl.Beta[12] = -0.0994
this->Impl.Beta[13] = -0.0243
this->Impl.Beta[14] = 0.1211
this->Impl.Beta[15] = -0.0363
this->Impl.Beta[16] = 1.0095
this->Impl.Beta[17] = 0.2499
this->Impl.Beta[18] = -0.5133
this->Impl.Beta[19] = -0.4869


*/
void Learner_fitWithoutValidation(incrementalRegressionLinear *this,
                                  const double X[100], const double Y[5])
{
  int i;
  if(DEBUG_LOW) printf("\n==> Learner_fitWithoutValidation ");	

  for(i=0;i<20;i++){
    if (DEBUG_LOW) printf("\nthis->Impl.Beta[%d] = %.4f ",i,this->Impl.Beta[i] );
  }  
  if (DEBUG_LOW) printf("\n this->IsWarm = %d ",this->IsWarm );  

  
  double gradBetaTotal[20];
  int b_i;

  int i1;
  int k;
  int nz;
  int pEnd;
  int qEnd;
  unsigned int qY;
  unsigned int val;
  bool indsToExclude[5];
  
  RegressionModel_prepareData(X, Y, true, indsToExclude);
  nz = (((indsToExclude[0] + indsToExclude[1]) + indsToExclude[2]) +
        indsToExclude[3]) +
       indsToExclude[4];
  if ((int)(5U - nz) != 0) {
    double shuffledIndices[5];
    double bias;
    double gradbiasTotal;
    double initLearnRate;
    double lambda;
    double lossScaler;
    double sumW;
    int idx[5];
    int iwork[5];
    unsigned int count;
    int currentBatchSize;
    bool exitg1;
    initLearnRate = this->Impl.LearnRate;
    bias = this->Impl.Bias;
    val = this->Impl.BatchIndex;
    lambda = this->Impl.Lambda;
    memset(&gradBetaTotal[0], 0, 20U * sizeof(double));
    gradbiasTotal = 0.0;
    if (5U - nz < 5U) {
      currentBatchSize = (int)(5U - nz);
    } else {
      currentBatchSize = 5;
    }
    b_rand(shuffledIndices);
    if (shuffledIndices[0] <= shuffledIndices[1]) {
      idx[0] = 1;
      idx[1] = 2;
    } else {
      idx[0] = 2;
      idx[1] = 1;
    }
    if (shuffledIndices[2] <= shuffledIndices[3]) {
      idx[2] = 3;
      idx[3] = 4;
    } else {
      idx[2] = 4;
      idx[3] = 3;
    }
    idx[4] = 5;
    i = 2;
    while (i < 5) {
      int i2;
      int j;
      i2 = i << 1;
      j = 1;
      for (pEnd = i + 1; pEnd < 6; pEnd = qEnd + i) {
        int kEnd;
        int p;
        int q;
        p = j;
        q = pEnd;
        qEnd = j + i2;
        if (qEnd > 6) {
          qEnd = 6;
        }
        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          b_i = idx[q - 1];
          i1 = idx[p - 1];
          if (shuffledIndices[i1 - 1] <= shuffledIndices[b_i - 1]) {
            iwork[k] = i1;
            p++;
            if (p == pEnd) {
              while (q < qEnd) {
                k++;
                iwork[k] = idx[q - 1];
                q++;
              }
            }
          } else {
            iwork[k] = b_i;
            q++;
            if (q == qEnd) {
              while (p < pEnd) {
                k++;
                iwork[k] = idx[p - 1];
                p++;
              }
            }
          }
          k++;
        }
        for (k = 0; k < kEnd; k++) {
          idx[(j + k) - 1] = iwork[k];
        }
        j = qEnd;
      }
      i = i2;
    }
    for (b_i = 0; b_i < 5; b_i++) {
      shuffledIndices[b_i] = idx[b_i];
    }
    count = 0U;
    if ((unsigned int)currentBatchSize == 5U - nz) {
      sumW = 0.0;
      for (i = 0; i < 5; i++) {
        if (!indsToExclude[(int)shuffledIndices[i] - 1]) {
          sumW++;
        }
      }
      lossScaler = (5.0 - (double)nz) / sumW;
    } else {
      unsigned int bCount;
      sumW = 0.0;
      bCount = 0U;
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 5)) {
        if (!indsToExclude[(int)shuffledIndices[i] - 1]) {
          sumW++;
          qY = bCount + 1U;
          if (bCount + 1U < bCount) {
            qY = MAX_uint32_T;
          }
          bCount = qY;
        }
        if (bCount == 0U) {
          exitg1 = true;
        } else {
          i++;
        }
      }
      lossScaler = (double)bCount / sumW;
    }
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 5)) {
      b_i = (int)shuffledIndices[i];
      if (!indsToExclude[b_i - 1]) {
        double grad[21];
        double currentBatchSize_tmp;
        qY = count + 1U;
        if (count + 1U < count) {
          qY = MAX_uint32_T;
        }
        count = qY;
        sumW = 0.0;
        for (i1 = 0; i1 < 20; i1++) {
          sumW += X[(b_i + 5 * i1) - 1] * this->Impl.Beta[i1];
        }
        sumW = (sumW + bias) - Y[b_i - 1];
        grad[20] = sumW;
        currentBatchSize_tmp = (double)currentBatchSize / 5.0 * lossScaler;
        for (i1 = 0; i1 < 20; i1++) {
          double d;
          d = sumW * X[(b_i + 5 * i1) - 1];
          grad[i1] = d;
          gradBetaTotal[i1] -= currentBatchSize_tmp * d;
        }
        gradbiasTotal -= currentBatchSize_tmp * grad[20];
      }
      if (count == (unsigned int)currentBatchSize) {
        qY = val + 1U;
        if (val + 1U < val) {
          qY = MAX_uint32_T;
        }
        val = qY;
        sumW = initLearnRate / (lambda * initLearnRate * (double)qY + 1.0);
        for (b_i = 0; b_i < 20; b_i++) {
          this->Impl.Beta[b_i] -=
              sumW * (lambda * this->Impl.Beta[b_i] -
                      gradBetaTotal[b_i] / (double)currentBatchSize);
        }
        bias += sumW * (gradbiasTotal / (double)currentBatchSize);
        exitg1 = true;
      } else {
        i++;
      }
    }
    this->Impl.Bias = bias;
    this->Impl.BatchIndex = val;
  }
  val = this->NumTrainingObservations;
  if (MAX_uint32_T - this->NumTrainingObservations >= 5U - nz) {
    qY = (val - nz) + 5U;
    if (qY < val) {
      qY = MAX_uint32_T;
    }
    val = qY;
  }
  this->NumTrainingObservations = val;
  if ((!this->IsWarm) && (val >= 50U)) {
    this->IsWarm = true;
  }

    for(i=0;i<20;i++){
    if (DEBUG_LOW) printf("\n this->Impl.Beta[%d] = %.4f ",i,this->Impl.Beta[i] );
  }  
  if (DEBUG_LOW) printf("\n this->IsWarm = %d ",this->IsWarm );  
    
  if(DEBUG_LOW) printf("\n<-- Learner_fitWithoutValidation ");	
}

/* End of code generation (Learner.c) */
