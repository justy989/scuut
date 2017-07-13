# scuut
simple c undefined unit test library  
  
Designed for small projects that want to quickly add unittests while in development.
 - single header file
 - automatically discovers tests when they are defined

## Example Usage
```c
#include "scut.h"

TEST(one_is_less_than_two){
     int a = 1;
     int b = 2;
     EXPECT(a < b);
}

TEST(three_is_greather_than_two){
     int a = 3;
     int b = 2;
     EXPECT(a > b);
}

TEST(zero_is_not_one){
     int a = 0;
     int b = 1;
     EXPECT(a != b);
}

int main(){
     RUN_TESTS();
}
```

## Caveat
Relies on global variables being assigned sequential memory locations, which is undefined behavior. Have fun!
