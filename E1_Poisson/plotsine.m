%#ok<*NOPTS>

filename = 'output.out' 
[r,x,y] = dat_import(filename);

figure
pcolor(x,y,r)
colormap(gray(20))
xlabel 'x'
ylabel 'y'
title 'RAW Data'