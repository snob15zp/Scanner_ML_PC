function filesave_ceval(data,foldername,filename,sz,t)
%-----------------------------------
%columnwise
%-----------------------------------
coder.inline('never');
if coder.target('MATLAB')
    save([foldername,'REF_',filename],'data','-ascii','-tabs')
else
  %path='c:\prezerv\';
  cpath=[foldername,0];
  %coder.updateBuildInfo('addIncludePaths','$(START_DIR)\codegen\lib\combineXY');
  %coder.cinclude('myabsval_initialize.h');
  %coder.cinclude('myabsval.h');
  %coder.cinclude('myabsval_terminate.h');
  coder.updateBuildInfo('addSourceFiles','filesave.cpp');
  coder.cinclude('filesave.h');
  %void filesave(const double *data, int  size1,int size2, char* path, char *filename);
  %s1=int32(0);
  %[s1,s2]=sz;%size(data);
  s1i=cast(sz(1),"int32");
  if s1i<1
      s1i=cast(1,"int32");
  end
  s2i=cast(sz(2),"int32");
  if s2i<1
      s2i=cast(1,"int32");
  end
%   ActVal2=[];
%   ActVal2(1:s1i,1:s2i)=data(1:s1i,1:s2i);
  coder.ceval('filesave', coder.ref(data),s1i,s2i,coder.ref(cpath),[filename,0],cast(t,"int32"));
  coder.ceval('filecomp', coder.ref(cpath),[filename,0]);

end
end

