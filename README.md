# scuut
simple c undefined unit test library  
  
Designed for small projects that want to quickly add unittests while in development.
 - single header file (tiny! ~40 lines)
 - automatically discovers tests when they are defined

## Example Usage
#### Passing Scenario
```c
// taken from example_pass.c
#include "scuut.h"

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

```bash
$ gcc example_pass.c -o example_pass
$ ./example_pass
executing 3 test(s)

all test(s) passed
$
```

#### Failing Scenario
```c
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
```

```bash
$ gcc example_fail.c -o example_fail
$ ./example_fail
executing 3 test(s)

example_fail.c:12: going_to_fail() FAILED expecting (a == b)

1 test(s) failed
$
```

## Caveat
Relies on global variables being assigned sequential memory locations, which is undefined behavior. Have fun!
