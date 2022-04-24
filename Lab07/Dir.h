#pragma once

#include "FileBase.h"

class Dir final : public FileBase {

  public:
      Dir(std::string);
      
      ~Dir ();

      void operator += (FileBase * );
      void operator -=(std::string);
      std::ostream& print(std::ostream &, int)const override;
      FileBase *makeCopy() const override;
      FileBase *get(std::string);
      Dir * getDir(std::string) const;
      void copy(FileBase*);


  protected:
      std::vector<FileBase*> _inDir;



};