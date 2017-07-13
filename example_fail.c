#include "scuut.h"

TEST(one_is_one){
     int a = 1;
     int b = 1;
     EXPECT(a == b);
}

TEST(one_is_zero){
     int a = 0;
     int b = 1;
     EXPECT(a == b);
}

TEST(one_is_two){
     int a = 2;
     int b = 1;
     EXPECT(a == b);
}

int main(){
     RUN_TESTS();
}
