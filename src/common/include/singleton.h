/*
 * @Author: guanwenjie 
 * @Date: 2021-02-24 15:31:03 
 * @Last Modified by: guanwenjie
 * @Last Modified time: 2021-02-24 17:32:25
 */

template<class CConcreteClass>
class CSingleton
{
public:
    static CConcreteClass * GetInstance();
};

template<class CConcreteClass>
CConcreteClass * CSingleton<CConcreteClass>::GetInstance()
{
    CConcreteClass *pInstance = nullptr;
    return pInstance;
}