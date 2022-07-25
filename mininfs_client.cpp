
// ecs251 miniNFS

#include <iostream>
#include "Shadow_Directory.h"
#include <unistd.h>
using namespace std;

int main()
{
  int n = 5;

  while (n > 0)
  {
    std::cout << "Didn't receive Ack in time. Resuming Search" << std::endl;
    n--;
    sleep(2);
  }

  std::cout << "Ack recieved. Facilitating communication" << std::endl;
  sleep(2);

  // Requesting for a file
  std::cout << "Reuesting File" << std::endl;
  sleep(2);
  Shadow_Directory dir_mount{"http://127.0.0.1:8384", "1234567890", "Directory", "00000002"};

  Json::Value result_000;

  std::cout << "Creating file" << std::endl;
  sleep(2);
  result_000 = dir_mount.Create("00000002", "my_first_file", "sattr dummy");

  std::cout << std::endl << result_000 << std::endl;

  result_000 = dir_mount.UpdateFile("00000002", "my_first_file", "sattr dummy", "22222222", "my_first_updated_file");

  std::cout << std::endl << result_000 << std::endl;

  std::cout << "Confirming file's existence" << std::endl;
  sleep(2);

  result_000 = dir_mount.LookUp("00000002", "my_first_file");

  // Checking send
  printf("\n Checking Sending of Files to the Client\n");
  sleep(2);
  result_000 = dir_mount.send("00000002", "my_first_file");

  printf("Zipping the file");
  sleep(2);
  result_000 = dir_mount.Zip("00000002", "my_first_file", "csv", "4Mb");

  result_000 = dir_mount.dumpJ();

  std::cout << result_000.toStyledString() << std::endl;

  return 0;
}
