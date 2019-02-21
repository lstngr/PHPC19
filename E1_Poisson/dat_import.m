function [res,x,y] = dat_import(filename)
    res = importdata(filename);
    npts = size(res,1);
    x = linspace(0,1,npts);
    y = x;
end