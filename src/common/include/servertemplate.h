/*
 * @Author: guanwenjie 
 * @Date: 2021-02-24 15:37:10 
 * @Last Modified by: guanwenjie
 * @Last Modified time: 2021-02-24 17:21:04
 */

#include <stdint.h>
#include <string>

class CServerTemplate
{
public:
    int32_t Init(const std::string &strConfigPath, bool bIsDaemon);
    int32_t MainLoop();
private:
    bool                bIsDaemon;  // 是否为守护进程
};