#include "phpcpp.h"
#include "test0001.h"
#include "test0002.h"
#include "test0003.h"
#include "test0004.h"
#include "test0005.h"
#include "test0006.h"
#include "test0007.h"
#include "issue114.h"
#include "issue229.h"
#include "issue234.h"
#include "issue249.h"
#include "issue254.h"
#include "issue260.h"
#include "issue261.h"
#include "issue269.h"
#include "issue273.h"
#include "issue289.h"
#include "issue293.h"

extern "C"
{
    PHPCPP_EXPORT void* get_module()
    {
        static Php::Extension extension("phpcpptest", "1.0");

        init_Test0001(extension);
        init_Test0002(extension);
        init_Test0003(extension);
        init_Test0004(extension);
        init_Test0005(extension);
        init_Test0006(extension);
        init_Test0007(extension);

        init_Issue114(extension);
        init_Issue229(extension);
        init_Issue234(extension);
        init_Issue249(extension);
        init_Issue254(extension);
        init_Issue260(extension);
        init_Issue261(extension);
        init_Issue269(extension);
        init_Issue273(extension);
        init_Issue289(extension);
        init_Issue293(extension);

        return extension.module();
    }
}
