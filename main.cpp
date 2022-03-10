#include <iostream>
#include "Queue.h"

using namespace std;

void show_menu();
enum commands { PUSH = 1, POP, PRINT, CLEAR, SELECT, COMPARE, ADD, SUB, ADD_DIV, COPY, EXIT };

int main() {
  bool is_exit = false;
  int act, num_q = 1, move, num_q2, num_q3;
  Queue queues[3] = {Queue(5), Queue(5), Queue(5)};
  for (int i = 0; i < 3; ++i) queues[i].fill_the_queue();
  system("cls");
  show_menu();

  while (!is_exit) {
    cout << "\n[Selected " << num_q << " queue]";
    cout << "\nEnter action: ";
    cin >> act;
    system("cls");
    show_menu();
    try {
      if (act == PUSH)
        ++queues[num_q - 1];
      else if (act == POP)
        --queues[num_q - 1];
      else if (act == CLEAR) {
        queues[num_q - 1].clear();
        cout << "The queue successfully cleared";
      } else if (act == PRINT)
        cout << queues[num_q - 1];
      else if (act == SELECT) {
        cout << "Select queue (1-3)>>" << endl;
        cin >> num_q;
      } else if (act == COMPARE) {
        cout << "Select comparison:\n\t1 - \"!=\"\n\t2 - \"==\"\n\t3 - \">\"\n\t4 - \"<\"\n\t5 - \">=\"\n\t6 - \"<=\" >>";
        cin >> move;
        cout << "What queue compare (1-3)? >>";
        cin >> num_q2;
        if (move == 1) cout << ((queues[num_q - 1] != queues[num_q2 - 1]) ? "true\n" : "false\n");
        else if (move == 2) cout << ((queues[num_q - 1] == queues[num_q2 - 1]) ? "true\n" : "false\n");
        else if (move == 3) cout << ((queues[num_q - 1] > queues[num_q2 - 1]) ? "true\n" : "false\n");
        else if (move == 4) cout << ((queues[num_q - 1] < queues[num_q2 - 1]) ? "true\n" : "false\n");
        else if (move == 5) cout << ((queues[num_q - 1] >= queues[num_q2 - 1]) ? "true\n" : "false\n");
        else if (move == 6) cout << ((queues[num_q - 1] <= queues[num_q2 - 1]) ? "true\n" : "false\n");
      } else if (act == ADD)
        queues[num_q - 1]++;
      else if (act == SUB)
        queues[num_q - 1]--;
      else if (act == ADD_DIV) {
        cout << "Select move:\n\t1 - \"+\"\n\t2 - \"/\" >>";
        cin >> move;
        cout << "Select second queue:";
        cin >> num_q2;
        cout << "Select result queue:";
        cin >> num_q3;
        if (move == 1) queues[num_q3 - 1] = queues[num_q - 1] + queues[num_q2 - 1];
        else if (move == 2) queues[num_q3 - 1] = queues[num_q - 1] / queues[num_q2 - 1];
      } else if (act == COPY) {
        cout << "Select queue:";
        cin >> num_q2;
        queues[num_q - 1] = queues[num_q2 - 1];
      } else if (act == EXIT)
        is_exit = true;
    }
    catch (const std::exception &e) {
      cout << e.what();
    }
  }
  return 0;
}

void show_menu() {
  cout << "1 - Add queue item\n2 - Pop an element from the queue\n3 - Display queue on screen\n4 - Clear queue\n";
  cout << "5 - Select queue\n6 - Compare queues\n7 - Add number to queue elements \n8 - Substitute from the queue elements\n";
  cout << "9 - Addition/division queues\n10 - Copy queues\n11 - Exit from the program\n\n";
}