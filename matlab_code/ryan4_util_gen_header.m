function ryan4_util_gen_header(x_norm,y_norm,Y,idx)

    len = length(x_norm);
    %idx = 1
    formatSpec_filename = 'x_norm_%d.h';
    filename = num2str(idx,formatSpec_filename);
    fid = fopen(filename,'w');

    formatSpec_variablename = 'double x_norm_%d[%d][20] = { \n' ;
    fprintf(fid,formatSpec_variablename,idx,len); 
    for i=1:len 
        str = num2str(x_norm(i,:));
        str = regexprep(str,'\s+',',');
        if i == len 
            fprintf(fid,'  {%s}  } ; \n',str);
        else
            fprintf(fid,'  {%s} , \n',str);
        end
    end 
    fclose(fid)
    
    len = length(y_norm);
    formatSpec_filename = 'y_norm_%d.h';
    filename = num2str(idx,formatSpec_filename);
    fid = fopen(filename,'w');

    formatSpec_variablename = 'double y_norm_%d[%d][1] = { \n' ;
    fprintf(fid,formatSpec_variablename,idx,len); 
    for i=1:len 
        str = num2str(y_norm(i,:));
        str = regexprep(str,'\s+',',');
        if i == len 
            fprintf(fid,'  {%s}  } ; \n',str);
        else
            fprintf(fid,'  {%s} , \n',str);
        end
    end 
    fclose(fid)

    len = length(Y);
    formatSpec_filename = 'Y_%d.h';
    filename = num2str(idx,formatSpec_filename);
    fid = fopen(filename,'w');

    formatSpec_variablename = 'double Y_%d[%d][1] = { \n' ;
    fprintf(fid,formatSpec_variablename,idx,len); 
    for i=1:len 
        str = num2str(Y(i,:));
        str = regexprep(str,'\s+',',');
        if i == len 
            fprintf(fid,'  {%s}  } ; \n',str);
        else
            fprintf(fid,'  {%s} , \n',str);
        end
    end 
    fclose(fid);

end