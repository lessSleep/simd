
#include <stdio.h>
#include <time.h>
#include <string>
class htimer {
public:
  htimer():title("Total time") { clock_gettime(CLOCK_MONOTONIC_RAW, &begin); };
  htimer(const char* s):title(s) { clock_gettime(CLOCK_MONOTONIC_RAW, &begin); };
  ~htimer(){
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    printf("%s : %f seconds\n",title.c_str(),
           (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
               (end.tv_sec - begin.tv_sec));
  };
  /*
  void start();
  void stop();
  void reset();
  double get_time();
  double get_time_ms();
  */
private:
  struct timespec begin, end;
  std::string title;
};
