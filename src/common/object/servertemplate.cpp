/*
 * @Author: guanwenjie 
 * @Date: 2021-02-24 16:10:49 
 * @Last Modified by: guanwenjie
 * @Last Modified time: 2021-02-25 17:16:08
 */

#include "servertemplate.h"
#include "miscutils.h"

int32_t CServerTemplate::Init(const std::string &strConfigPath, bool bIsDaemon)
{
    if (bIsDaemon)
    {
        StartDaemon();
    }
    return 0;
}

int32_t CServerTemplate::MainLoop()
{
    return 0;
}