#include "VectorQ.h"

void VectorQ::add(std::unique_ptr<Person> newClient){

  _queue.push_back(std::move(newClient));

}

void VectorQ::print(std::string header)const{

  std::cout<< header<<std::endl;

  for(auto& client : _queue)
  {
    client->print();
    std::cout<<"\n";
  }
  std::cout<<"\n";
}

std::vector<Woman*> VectorQ::getWomen()const{

  std::vector<Woman*> result;
  for(auto& client : _queue)
  {
    if(client->is_man() == false)
    {
      result.push_back(dynamic_cast<Woman*>(client.get()));
    }
  }
  return result;
}

void VectorQ::countNames()const{
  std::map<std::string, int> count;

  for(auto& client : _queue)
  {
    ++count[client.get()->name()];
  }

  for(auto& pair: count)
  {
    std::cout<<pair.first<<": "<<pair.second << std::endl;
  }

}

void VectorQ::haircut(std::string name){

 


}
void VectorQ::haircut(){

}
void VectorQ::shave(std::string){

}
void VectorQ::shave(){

}