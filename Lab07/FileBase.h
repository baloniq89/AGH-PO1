#pragma once

#include <iostream>
#include <string>
#include <vector>

class FileBase {

  public:
    FileBase(std::string name) : _name(name) {}
    virtual std::ostream& print(std::ostream & stm, int spaces = 0) const = 0;

    virtual std::string getName() const { return _name;}

    virtual ~FileBase() = default;

    friend std::ostream& operator <<(std::ostream & stm, const FileBase & object)
    {
      object.print(stm, 0);
      return stm;
    }

    virtual FileBase *makeCopy() const = 0;

  protected:
    std::string _name;
};