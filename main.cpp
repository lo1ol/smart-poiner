#include <iostream>
#include <smart_ptr.h>

using namespace std;

struct klass{
    int num;
    char sym;
};

int main()
{
    {
        smart_ptr<int> sptr(new int[10]);
    }
    {
        smart_ptr<int> sptr(new int[10]);
        for(int i=0; i<10; i++)
            sptr[i] = i*10;

        smart_ptr<int> sptr2;
        sptr[9] = 11;
        sptr2 = sptr;
        for(int i=0; i<10; i++)
            printf("x[%d] == %d\n", i, sptr[i]);
        printf("\n");
        std::cout<<"Number of pointer on array: "<<sptr.get_count()<<endl;
        sptr2[5] = 124;
        sptr2.reset();
        for(int i=0; i<10; i++)
            printf("x[%d] == %d\n", i, sptr[i]);
    }
    {
        smart_ptr<klass> sptr(new klass);
    }
    {
        smart_ptr<int> sptr1(new int [10]);
        smart_ptr<int> sptr2(new int [10]);
        for(int i=0; i<10; i++)
            sptr1[i] = i;

        for(int i=0; i<10; i++)
            sptr2[i] = i*11;

        sptr1.swap(sptr2);

        cout<<"Smart pointer1\n";
        for(int i=0; i<10; i++)
            printf("x[%d] == %d\n", i, sptr1[i]);
        cout<<"Smart pointer2\n";
        for(int i=0; i<10; i++)
            printf("x[%d] == %d\n", i, sptr2[i]);
    }
}
