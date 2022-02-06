void read_loop_trees()
{
  TString roostr = "";

  ////////////////////////////////////////////////////
  
  roostr = "roofile_obj.root";
  TFile *roofile = new TFile(roostr, "read");
  
  TIter next(roofile->GetListOfKeys());
  TKey *key;
  TTree *tree;

  int line = 0;

  cout<<endl;
  while( (key=(TKey*)next()) ) {
    if( (strcmp(key->GetClassName(), "TTree")) ) continue;
    line++;
    TString strname = key->GetName();
    tree = (TTree*)roofile->Get(strname);
    cout<<TString::Format(" ---> %3d  %-40s  %8d", line, strname.Data(), (int)(tree->GetEntries()))<<endl;
    delete tree;
  }
  cout<<endl;
  
}
