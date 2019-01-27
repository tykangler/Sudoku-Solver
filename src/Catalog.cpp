#include "Catalog.hpp"
#include <dirent.h>
#include <iostream>

namespace Catalog {

std::ifstream prompt_for_board() {
   std::cout << "pick a board: \n";
   std::cout << "------------------------";
   DIR *dp = opendir("../inputs");
   dirent *ep;
   int fileno = 0;
   while (ep = readdir(dp)) {
      if (ep->d_name[0] != '.') {
         putc('\n', stdout);
         fileno++;
         printf("%d: ", fileno);
      }
      for (int i = 0; ep->d_name[i] != EOF && ep->d_name[i] != '.'; i++) {
         putc(ep->d_name[i], stdout);
      }
   }
   closedir(dp);
   std::cout << "\n\n>>> ";
   std::string fname;
   std::cin >> fname;
   return std::ifstream{"../inputs/" + fname + ".sb"};
}

}