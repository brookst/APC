#ifndef _MAGVECTOR_H_
#define _MAGVECTOR_H_

#include <vector>
#include <iostream>
#include <cmath>
#include <stdexcept>

class MagVector
{
private:

  std::vector<float> _content;

public:

  MagVector(const int& _size):
    _content(_size,0.){
  };

  virtual ~MagVector(){};

  void print(){
    std::vector<float>::const_iterator vItr = _content.begin();
    std::vector<float>::const_iterator vEnd = _content.end();
    std::cout << "vector\t";
    for (; vItr!=vEnd; ++vItr){
      std::cout << *vItr << ", ";
    }
    std::cout << std::endl;
  }

  void append(const float& _new){
    _content.push_back(_new);
  }

  void set(const int& _index,const float& _new){
    if(_index>-1 && _index<_content.size())
      _content[_index] = (_new);
    else
      throw std::out_of_range("MagVector::set >> index out of range");
  }

  float get(const int& _index){
    try{
      return _content.at(_index);
    }
    catch(...){
      std::cerr << __FILE__<< ":\t" << "index out of range!\n";
      return 0.;
    }
  }

  float magnitude() const {
    float valueSquared = 0.;
    for (short index=0; index<_content.size(); ++index){
      valueSquared += ((_content[index])*(_content[index]));
    }

    if(valueSquared >= 0.)
      return std::sqrt(valueSquared);
    else
      return -1.;
  }


  void add(const MagVector& _rhs){
    if(_rhs._content.size()!=this->_content.size())
      throw std::logic_error("dimensions does not fit");

    float returnValue = 0.;
    for (short index=0; index<_rhs._content.size(); ++index){
      _content[index]+=_rhs._content[index];
    }
    return;
  }
  
};

#endif /* _MAGVECTOR_H_ */
