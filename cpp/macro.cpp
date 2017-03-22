//#define fish

#ifdef fish
#define FF(x) (x)*(x)
#else
#define FF(x)
#endif

#define FISH(x) \
    printf (x)

int main()
{
    FF("fish");
    FISH("hello");
    ;
    ;
    ;
    ;
    ;
    ;

}
