#include<iostream>
using namespace std;

float Li(int point_x, int k, float *tab, int length)
{
    int i;
    float result = 1;
    for(i = 0; i < length; i++)
    {
        if(i == k) continue;
        result *= float(point_x - tab[i])/(tab[k] - tab[i]);
    }
    return result;
}


float min_(float *tab, int length)
{
    int i;
    float min_dig = tab[0];
    for(i = 0; i < length; i++) if(tab[i] < min_dig) min_dig = tab[i];
    return min_dig;
}


float max_(float *tab, int length)
{
    int i;
    float max_dig = tab[0];
    for(i = 0; i < length; i++) if(tab[i] > max_dig) max_dig = tab[i];
    return max_dig;
}


int main()
{
    int i;
    float tab_x[20];  // don't need more point
    float tab_f[20];
    float point_x;
    int len;
    float result = 0;

    cout<<"Give x elements in ascending order!\nGive the number of points: ";
    cin>>len;
    for(i = 0; i<len; i++)
    {
        cout<<"Give x"<<i<<" point: ";
        cin>>tab_x[i];
        cout<<"Give func(x"<<i<<"): ";
        cin>>tab_f[i];
    }
    cout<<"Give a point in which you need to define the value of the function: ";
    cin>>point_x;

    float min_dig = min_(tab_x, len);
    float max_dig = max_(tab_x, len);

    if(point_x < min_dig || point_x>max_dig)
    {
        cout<<"Your point must be between "<<min_dig<<" and "<<max_dig<<endl;
        return 0;
    }

    for(i = 0; i < len; i++)
    {
        result += tab_f[i]*Li(point_x, i, tab_x, len);
    }

    cout<<"Func("<<point_x<<") = "<<result<<endl;

    return 0;
}
