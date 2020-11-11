#ifndef MULTIPLE_INHERITABLE_ENABLE_SHARED_FROM_THIS_H_
#define MULTIPLE_INHERITABLE_ENABLE_SHARED_FROM_THIS_H_

#include <memory>

/* Trick to allow multiple inheritance of objects
 * inheriting shared_from_this.
 * cf. https://stackoverflow.com/a/12793989/587407
 */

/* First a common base class
 * of course, one should always virtually inherit from it.
 */

class MultipleInheritableEnableSharedFromThis : public std::enable_shared_from_this<MultipleInheritableEnableSharedFromThis>
{
public:
    virtual ~MultipleInheritableEnableSharedFromThis()
    {
    }
};

#endif /* MULTIPLE_INHERITABLE_ENABLE_SHARED_FROM_THIS_H_ */