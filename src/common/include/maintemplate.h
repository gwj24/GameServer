/*
 * @Author: guanwenjie 
 * @Date: 2021-02-24 15:16:48 
 * @Last Modified by: guanwenjie
 * @Last Modified time: 2021-02-25 16:56:27
 */

#include <stdint.h>
#include <unistd.h>
#include <string>
#include <csignal>
#include "singleton.h"
#include "serverdefine.h"

/*
 * CConcreteServer 需要实现以下接口
 * int32_t Init();
 * int32_t MainLoop();
 */

static uint32_t g_dwSignal = 0;

void SignalHandler(int32_t nSignal)
{
    switch (nSignal)
    {
    case SIGNAL_EXIT:
        {
            g_dwSignal |= SIGNAL_SERVER_EXIT;
        }
        break;
    
    default:
        // TODO 告警
        break;
    }
}

template<class CConcreteServer>
class CMainTemplate
{
public:
    int32_t Run(int32_t argc, char *argv[]);
};

template<class CConcreteserver>
int32_t CMainTemplate<CConcreteserver>::Run(int32_t argc, char *argv[])
{
    const char *pszOptString = "c:d";
    bool bIsDaemon = false;
    std::string strConfigPath = "";
    int32_t opt = 0;
    while((opt = getopt(argc, argv, pszOptString)) != -1)
    {
        switch (opt)
        {
            case 'c':
            {
                strConfigPath = optarg;
            }
            break;
            case 'd':
            {
                bIsDaemon = true;
            }
            break;
            default:
            {
                // TODO 告警
            }
            break;
        }
    }
    if (strConfigPath.length() == 0)
    {
        // TODO
        return -1;
    }
    CConcreteserver *poConcreteServer = CSingleton<CConcreteserver>::GetInstance();
    if (poConcreteServer == nullptr)
    {
        // TODO
        return -1;
    }
    if (poConcreteServer->Init(strConfigPath, bIsDaemon) != 0)
    {
        // TODO 错误处理
        return -1;
    }

    // signal 处理
    signal(SIGNAL_EXIT, SignalHandler);

    poConcreteServer->MainLoop();
    return 0;
}
