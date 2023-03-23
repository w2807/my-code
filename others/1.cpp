#include<bits/stdc++.h>
#include<gmpxx.h>
using namespace std;
auto getPrimePow(size_t n)
{
    vector<pair<size_t,size_t>> tab; 
    vector<bool> ar;
    ar.resize(n+1);
    tab.reserve(2*n/log(n));
    for (size_t i=2;i<=n;++i)
    {
        if (!ar[i])
        {
            size_t cnt=0;
            for (size_t j=i;j<=n;j+=i)
            {
                ar[j]=true;
            }
            for (size_t j=i;j<=n;j*=i)
            {
                cnt+=n/j;
            }
            tab.emplace_back(i,cnt);
        }
    }
    return tab;
}

template<typename iter>
mpz_class cal_odd(iter beg,iter end)
{
    if (beg==end)
    {
        if (beg->second%2)
        {
            beg->second/=2;
            return beg->first;
        }
        else
        {
            beg->second/=2;
            return 1;
        }
    }
    auto mid=beg+(end-beg)/2;
    return cal_odd(beg,mid)*cal_odd(mid+1,end);
}

mpz_class cal(std::vector<std::pair<size_t, size_t>>&tab)
{
    mpz_class ans=1;
    if (tab.size())
    {
        ans=cal_odd(tab.begin(),tab.end());
        while (tab.size()&&tab.back().second==0)
            tab.pop_back();
        auto subans=cal(tab);
        ans*=subans*subans;
    }
    return ans;
}

mpz_class Factorial(size_t n)
{
    auto tab=getPrimePow(n);
    return cal(tab);
}

int main()
{
    size_t i;
    std::cin>>i;
    auto answer=Factorial(i);
    //std::cout<<answer<<std::endl;
    //有趣的是，单独的进制转换，其时间复杂度是nlog^2n，其系数远大于乘法，导致最终计算时需要的时间比阶乘还多一点。
    return 0;
}