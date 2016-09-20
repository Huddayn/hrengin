#include <stdexcept>
#include <aw/utility/test.h>

TestFile( "string::join" );

Test(always_fail0) { Checks { TestAssert(1 == 2); } }
Test(always_fail1) { Checks { TestAssert(false); } }
Test(always_fail2) { Checks { TestEqual(1, 2); } }
Test(always_fail3) { Checks { throw "what is this"; } }
Test(always_fail4) { Checks { throw std::logic_error("you suck"); } }
Test(always_fail5) { Checks { TestEqual(1, 2); } }
Test(always_fail6) { Checks { TestEqual(1, 2); } }
Test(always_fail7) { Checks { TestEqual(1, 2); } }
Test(always_fail8) { Checks { TestEqual(1, 2); } }
Test(always_fail9) { Checks { TestEqual(1, 2); } }
Test(always_faila) { Checks { TestEqual(1, 2); } }
Test(always_failb) { Checks { TestEqual(1, 2); } }
Test(always_failc) { Checks { TestEqual(1, 2); } }
Test(always_faild) { Checks { TestEqual(1, 2); } }
Test(always_faile) { Checks { TestEqual(1, 2); } }
Test(always_failf) { Checks { TestEqual(1, 2); } }

RunTests();
