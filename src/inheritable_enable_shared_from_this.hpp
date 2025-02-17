#ifndef INHERITABLE_ENABLE_SHARED_FROM_THIS_H_
#define INHERITABLE_ENABLE_SHARED_FROM_THIS_H_

#include <memory>
#include "MultipleInheritableEnableSharedFromThis.hpp"

/* Trick to allow multiple inheritance of objects
 * inheriting shared_from_this.
 * cf. https://stackoverflow.com/a/12793989/587407
 */

/* First a common base class
 * of course, one should always virtually inherit from it.
 */

template <class T>
class inheritable_enable_shared_from_this : virtual public MultipleInheritableEnableSharedFromThis
{
public:
  std::shared_ptr<T> shared_from_this()
  {
    return std::dynamic_pointer_cast<T>(MultipleInheritableEnableSharedFromThis::shared_from_this());
  }
  /* Utility method to easily downcast.
   * Useful when a child doesn't inherit directly from enable_shared_from_this
   * but wants to use the feature.
   */
  template <class Down>
  std::shared_ptr<Down> downcasted_shared_from_this()
  {
    return std::dynamic_pointer_cast<Down>(MultipleInheritableEnableSharedFromThis::shared_from_this());
  }
};

#endif /* INHERITABLE_ENABLE_SHARED_FROM_THIS_H_ */