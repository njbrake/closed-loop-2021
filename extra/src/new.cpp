#include "new.h"

namespace Loopy {
Closed::Closed() { thing_ = 2; }

int Closed::getThing() { return thing_; }
void Closed::setThing(int blah) { thing_ = blah; }
} // namespace Loopy