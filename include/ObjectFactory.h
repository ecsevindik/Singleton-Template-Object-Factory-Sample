#ifndef OBJECTFACTORY_H_
#define OBJECTFACTORY_H_

#include <map>
#include <memory>

/*
 * Singleton template factory class 
*/
template <
  class AbstractObject,
  typename IdentifierType,
  typename ObjectCreator
>
class ObjectFactory {
public:
  static ObjectFactory& Instance(){
      static ObjectFactory instance; // Guaranteed to be destroyed.
                                       // Instantiated on first use.
      return instance;
  }

  bool Register(const  IdentifierType& id, ObjectCreator creator){
    return associations_.insert(typename AssocMap::value_type(id,creator)).second;
  }

  bool Unregister(const IdentifierType& id){
    return associations_.erase(id) == 1;
  }

  template<typename ...Params>
  std::unique_ptr<AbstractObject> CreateObject(const IdentifierType& id, Params&& ...params){
    typename AssocMap::const_iterator it = associations_.find(id);
    if(it == associations_.end()){
      throw std::runtime_error("Unknown object type identifier encountered");    
    }
    // Invoke the creation function
    AbstractObject *strategy = (it->second)(std::forward<Params>(params)...);
    return std::unique_ptr<AbstractObject>(strategy);
  }

private:
  ObjectFactory(){}
  ObjectFactory(ObjectFactory& other) = delete; // copy-constructor delete
  ObjectFactory(ObjectFactory&& other) = delete; // move-constructor delete
  ObjectFactory& operator=(const ObjectFactory &) = delete; // assignment operator delete
  ObjectFactory& operator=(ObjectFactory&&) = delete; // move-assignment operator delete

  using AssocMap = std::map<IdentifierType, ObjectCreator>;
  AssocMap associations_;  

};

#endif // OBJECTFACTORY_H_