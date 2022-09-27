// main
//
#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(const int argc, const char* argv[]) {
	if (argc < 2) {
		printf("usage: %s <dn>\n", argv[0]);
		return -1;
	}
	struct hostent * ht1;
	ht1 = gethostbyname(argv[1]);

	if (ht1) {
		int len = sizeof(ht1->h_addr_list)/sizeof(ht1->h_addr_list[0]);
		for (int i =0; i< len; i++) {
			char buffer[30];
			printf("ip:%s\n",inet_ntop(ht1->h_addrtype,ht1->h_addr_list[i],buffer,30));
			printf(":%s\n",ht1->h_aliases[i]);
		}
	} 
	else {
		printf("fail: %s\n", argv[1]);
	}
}
