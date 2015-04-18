if isempty(currentFigures), currentFigures = []; end;
close(setdiff(findall(0, 'type', 'figure'), currentFigures))
clear mex
delete *.mexw64
rmdir('C:\Users\William Mackay\Documents\DOCUMENTS\MATLAB\coderdemo_averaging_filter\codegen','s');
delete C:\Users\William Mackay\Documents\DOCUMENTS\MATLAB\coderdemo_averaging_filter\averaging_filter.m
clear all
load old_workspace
delete old_workspace.mat
delete C:\Users\William Mackay\Documents\DOCUMENTS\MATLAB\coderdemo_averaging_filter\cleanup.m
cd C:\Users\William Mackay\Documents\DOCUMENTS\MATLAB
rmdir C:\Users\William Mackay\Documents\DOCUMENTS\MATLAB\coderdemo_averaging_filter
