#include "scuut.h"

TEST(going_to_pass){
     int a = 1;
     int b = 1;
     EXPECT(a == b);
}

TEST(going_to_fail){
     int a = 0;
     int b = 1;
     EXPECT(a == b);
}

TEST(never_reached){
     int a = 1;
     int b = 1;
     EXPECT(a == b);
}

int main(){
     RUN_TESTS();
}
