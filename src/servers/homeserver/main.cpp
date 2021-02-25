/*
 * @Author: guanwenjie 
 * @Date: 2021-02-24 16:25:08 
 * @Last Modified by: guanwenjie
 * @Last Modified time: 2021-02-24 17:26:13
 */

#include <stdint.h>
#include "maintemplate.h"
#include "homeserver.h"

int32_t main(int32_t argc, char *argv[])
{
    auto *poHomeServer = new CMainTemplate<CHomeServer>();
    if (poHomeServer == nullptr)
    {
        // TODO
        return -1;
    }
    poHomeServer->Run(argc, argv);
    return 0;
}