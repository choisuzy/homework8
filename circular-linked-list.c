#include<stdio.h>
#include<stdlib.h>
/* 필요한 헤더파일 추가 */

typedef struct Node { /* struct Node에 타입이 다른 데이터들을 그룹화 */
	int key; /* key를 int형으로 선언 */
	struct Node* llink; /* 구조체 Node포인터 llink를 선언 */ /* 위에서 typedef struct로 선언을 해주지 않았기에 struct를 써줘야함 */
	struct Node* rlink; /* 구조체 Node포인터 rlink를 선언 */ /* 위에서 typedef struct로 선언을 해주지 않았기에 struct를 써줘야함 */
} listNode; /* 구조체 호출용 이름 */

/* 함수 리스트 */
int initialize(listNode** h); /* 이중포인터를 매개변수로 하여 headNode에 메모리를 할당하여 초기화하는 initialize 함수 선언 */
int freeList(listNode* h); /* 할당된 메모리를 모두 해제하는 freeList 함수 선언 */
int insertLast(listNode* h, int key); /* key에 대한 노드 하나를 추가하는 insertLast 함수 선언 */
int deleteLast(listNode* h); /* list의 마지막 노드를 삭제하는 deleteLast 함수 선언 */
int insertFirst(listNode* h, int key); /* list 처음에 key에 대한 노드 하나를 추가하는 insertFirst 함수 선언 */
int deleteFirst(listNode* h); /* list의 첫번째 노드를 삭제하는 deleteFirst 함수 선언 */
int invertList(listNode* h); /* 리스트의 링크를 역순으로 재 배치하는 invertList 함수 선언 */
int insertNode(listNode* h, int key); /* 리스트를 검색하여 입력받은 key값보다 큰 값이 나오는 노드 바로 앞에 삽입하는 insertNode 함수 선언 */
int deleteNode(listNode* h, int key); /* list에서 key에 대한 노드를 삭제하는 deleteNode 함수 선언 */

void printList(listNode* h); /* list를 print하는 printList 함수 선언 */



int main()
{
	char command; /* command를 char형으로 선언 */
	int key; /* key를 int형으로 선언 */
	listNode* headnode=NULL; /* headNode포인터 headnode를 빈공간으로 지정 */

    printf("[----- [Choi Suzy]  [2021024135] -----]\n");

	do{
		printf("----------------------------------------------------------------\n"); /* print */
		printf("                  Doubly Circular Linked List                   \n"); /* print */
		printf("----------------------------------------------------------------\n"); /* print */
		printf(" Initialize    = z           Print         = p \n"); /* print */
		printf(" Insert Node   = i           Delete Node   = d \n"); /* print */
		printf(" Insert Last   = n           Delete Last   = e\n"); /* print */
		printf(" Insert First  = f           Delete First  = t\n"); /* print */
		printf(" Invert List   = r           Quit          = q\n"); /* print */
		printf("----------------------------------------------------------------\n"); /* print */

		printf("Command = "); /* print */
		scanf(" %c", &command); /* char형 command를 입력자에게 입력받음 */

		switch(command) { /* command가 ~이면 조건문 */
		case 'z': case 'Z': /* command가 z나 Z면 */
			initialize(&headnode); /* initialize(&headnode)함수 headnode에 넣음 */
			break; /* 조건식을 빠져나옴 */
		case 'p': case 'P': /* command가 p나 P면 */
			printList(headnode); /* printList(headnode)함수 실행 */
			break; /* 조건식을 빠져나옴 */
		case 'i': case 'I': /* command가 i나 I면 */
			printf("Your Key = "); /* print */
			scanf("%d", &key); /* int형 key를 입력자에게 입력받음 */
			insertNode(headnode, key); /* insertNode함수 호출 */
			break; /* 조건식을 빠져나옴 */
		case 'd': case 'D': /* command가 d나 D이면 */
			printf("Your Key = "); /* print */
			scanf("%d", &key); /* int형 key를 입력자에게 입력받음 */
			deleteNode(headnode, key);
			break; /* 조건식을 빠져나옴 */
		case 'n': case 'N': /* command가 n이나 N이면 */
			printf("Your Key = "); /* print */
			scanf("%d", &key); /* int형 key를 입력자에게 입력받음 */
			insertLast(headnode, key); /* insertLast함수 호출 */
			break; /* 조건식을 빠져나옴 */
		case 'e': case 'E': /* command가 e나 E이면 */
			deleteLast(headnode); /* deleteLast함수 호출 */
			break; /* 조건식을 빠져나옴 */
		case 'f': case 'F': /* command가 f나 F면 */
			printf("Your Key = "); /* print */
			scanf("%d", &key); /* int형 key를 입력자에게 입력받음 */
			insertFirst(headnode, key); /* insertFirst함수 호출 */
			break; /* 조건식을 빠져나옴 */
		case 't': case 'T': /* command가 t나 T면 */
			deleteFirst(headnode); /* deleteFirst함수 호출 */
			break; /* 조건식을 빠져나옴 */
		case 'r': case 'R': /* command가 r이나 R면 */
			invertList(headnode); /* invertList함수 호출 */
			break; /* 조건식을 빠져나옴 */
		case 'q': case 'Q': /* command가 q나 Q이면 */
			freeList(headnode); /* freeList함수 호출 */
			break; /* 조건식을 빠져나옴 */
		default: /* 위의 알파벳이 다 아니면 */
			printf("\n       >>>>>   Concentration!!   <<<<<     \n"); /* print */
			break; /* 조건식을 빠져나옴 */
		}

	}while(command != 'q' && command != 'Q'); /* command가 q가 아니고 Q가 아니라면 do루프 계속 돎 */

	return 1; /* 1을 반환함 */
}


int initialize(listNode** h) { /* 이중포인터를 매개변수로 하여 headNode에 메모리를 할당하여 초기화하는 initialize 함수 정의 */

	/* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
	if(*h != NULL) /* 포인터 headNode가 NULL이 아니면 */
		freeList(*h); /* 할당된 메모리를 모두 해제시키는 freeList 함수 호출 */

	/* headNode에 대한 메모리를 할당하여 리턴 */
	*h = (listNode*)malloc(sizeof(listNode)); /* listNode크기만큼을 동적할당한 listNode포인터를 포인터h에 넣음 */
	(*h)->rlink = *h; /* 포인터h의 rlink부분에 포인터h를 넣음 */
	(*h)->llink = *h; /* 포인터h의 llink부분에 포인터h를 넣음 */
	(*h)->key = -9999; /* 포인터h의 key부분에 -9999를 넣음 */
	return 1; /* 1를 반환함 */
}

int freeList(listNode* h){ /* 할당된 메모리를 모두 해제하는 freeList 함수 정의 */

	if(h->rlink == h) /* h의 rlink부분이 h라면 */
	{
		free(h); /* h를 free시킴 */
		return 1; /* 1을 반환함 */
	}

	listNode* p = h->rlink; /* h의 rlink부분을 listNode포인터 p에 넣음 */

	listNode* prev = NULL; /* listNode포인터 prev를 NULL로 만듦 */
	while(p != NULL && p != h) { /* p가 NULL이 아니고 h가 아니면 */
		prev = p; /* p를 prev에 넣음 */
		p = p->rlink; /* p의 link부분을 p에 넣음 */
		free(prev); /* prev를 free시킴 */
	}
	free(h); /* h를 free시킴 */
	return 0; /* 0을 반환함 */
}



void printList(listNode* h) { /* list를 print하는 printList 함수 정의 */
	int i = 0; /* int형 i를 0으로 초기화 */
	listNode* p; /* listNode포인터 p 선언 */

	printf("\n---PRINT\n"); /* print */

	if(h == NULL) { /* h가 빈공간이라면 */
		printf("Nothing to print....\n"); /* print */
		return; /* 반환함 */
	}

	p = h->rlink; /* h의 first부분을 p에 넣음 */

	while(p != NULL && p != h) { /* p가 빈공간이 아니고 h가 아니면 */
		printf("[ [%d]=%d ] ", i, p->key); /* i와 p의 key값을 차례대로 넣어 print */
		p = p->rlink; /* p에 p의 rlink부분을 넣음 */
		i++; /* 하나씩 증가시킴 */
	}
	printf("  items = %d\n", i); /* i값을 넣어 print */


	/* print addresses */
	printf("\n---checking addresses of links\n"); /* print */
	printf("-------------------------------\n"); /* print */
	printf("head node: [llink]=%p, [head]=%p, [rlink]=%p\n", h->llink, h, h->rlink); /* h의 llink, h의 rlink부분을 차례대로 넣어 print */

	i = 0; /* i에 0을 넣음 */
	p = h->rlink; /* p에 h의 rlink부분을 넣음 */
	while(p != NULL && p != h) { /* p가 빈공간이 아니고 h가 아니면 */
		printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key, p->llink, p, p->rlink); /* i, p의 key부분, p의llink, p의 rlink부분을 차례대로 넣어 print */
		p = p->rlink; /* p에 p의 rlink부분을 넣음 */
		i++; /* 하나씩 증가시킴 */
	}

}



/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(listNode* h, int key) { /* key에 대한 노드 하나를 추가하는 insertLast 함수 정의 */

	if (h == NULL) return -1; /* h가 null이면 -1을 반환함 */

	listNode* node = (listNode*)malloc(sizeof(listNode)); /* listNode크기만큼을 동적할당한 listNode포인터를 listNode포인터 node에 넣음 */
	node->key = key; /* node의 key부분에 key값을 넣음 */
	node->rlink = NULL; /* node의 rlink부분을 빈공간으로 만듦 */
	node->llink = NULL; /* node의 llink부분을 빈공간으로 만듦 */

	if (h->rlink == h) /* 첫 노드로 삽입 */ /* h의 rlink부분이 h라면 */
	{
		h->rlink = node; /* h의 rlink부분에 node을 넣음 */
		h->llink = node; /* h의 llink부분에 node을 넣음 */
		node->rlink = h; /* node의 rlink부분에 h를 넣음 */
		node->llink = h; /* node의 llink부분에 h를 넣음 */
	} else {  /* h의 rlink부분이 h가 아니라면 */
		h->llink->rlink = node; /* h의 llink의 rlink부분에 node을 넣음 */
		node->llink = h->llink; /* node의 llink부분에 h의 llink부분을 넣음 */
		h->llink = node; /* h의 llink부분에 node을 넣음 */
		node->rlink = h; /* node의 rlink부분에 h를 넣음 */
	}

	return 1; /* 1을 반환함 */
}


/**
 * list의 마지막 노드 삭제
 */
int deleteLast(listNode* h) { /* list의 마지막 노드를 삭제하는 deleteLast 함수 정의 */
 
	if (h->llink == h || h == NULL) /* h의 llink부분이 h이거나 빈공간이라면 */
	{
		printf("nothing to delete.\n"); /* print */
		return 1; /* 1을 반환함 */
	}

	listNode* nodetoremove = h->llink; /* listNode포인터 nodetoremove에 h의 llink를 넣음 */

	/* link 정리 */
	nodetoremove->llink->rlink = h; /* nodetoremove의 llink의 rlink부분에 h를 넣음 */
	h->llink = nodetoremove->llink; /* h의 llink부분에 nodetoremove의 llink부분을 넣음 */

	free(nodetoremove); /* nodetoremove를 free시킴 */

	return 1; /* 1을 반환함 */
}


/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(listNode* h, int key) { /* list 처음에 key에 대한 노드 하나를 추가하는 insertFirst 함수 정의 */

	listNode* node = (listNode*)malloc(sizeof(listNode)); /* listNode크기만큼을 동적할당한 listNode포인터를 listNode포인터 node에 넣음 */
	node->key = key; /* node의 key부분에 key값을 넣음 */
	node->rlink = NULL; /* node의 rlink부분을 빈공간으로 만듦 */
	node->llink = NULL; /* node의 llink부분을 빈공간으로 만듦 */


	node->rlink = h->rlink; /* node의 rlink부분에 h의 rlink부분을 넣음 */
	h->rlink->llink = node; /* h의 rlink의 llink부분에 node를 넣음 */
	node->llink = h; /* node의 llink부분에 h를 넣음 */
	h->rlink = node; /* h의 rlink부분에 node를 넣음 */


	return 1; /* 1을 반환함 */
}

/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(listNode* h) { /* list의 첫번째 노드를 삭제하는 deleteFirst 함수 정의 */

	if (h == NULL || h->rlink == h) /* h가 빈공간이거나 h의 rlink부분이 h라면 */
	{
		printf("nothing to delete.\n"); /* print */
		return 0; /* 0을 반환함 */
	}

	listNode* nodetoremove = h->rlink; /* listNode포인터 nodetoremove에 h의 rlink부분을 넣음 */
 
	/* link 정리 */
	nodetoremove->rlink->llink = h; /* nodetoremove의 rlink의 llink부분에 h를 넣음 */
	h->rlink = nodetoremove->rlink; /* h의 rlink부분에 nodetoremove의 rlink부분을 넣음 */

	free(nodetoremove); /* nodetoremove를 free시킴 */

	return 1; /* 1을 반환함 */

}


/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(listNode* h) { /* 리스트의 링크를 역순으로 재 배치하는 invertList 함수 정의 */


	if(h->rlink == h || h == NULL) { /* h의 rlink부분이 h이거나 빈공간이라면 */
		printf("nothing to invert...\n"); /* print */
		return 0;  /* 0을 반환함 */
	}
	listNode *n = h->rlink; /* listNode포인터n에 h의 rlink부분을 넣음 */
	listNode *trail = h; /* listNode포인터trail에 h를 넣음 */
	listNode *middle = h; /* listNode포인터middle에 h를 넣음 */

	/* 최종 바뀔 링크 유지 */
	h->llink = h->rlink; /* h의 llink부분에 h의 rlink부분을 넣음 */

	while(n != NULL && n != h){ /* n이 빈공간이 아니고 h가 아니라면 */
		trail = middle; /* trail에 middle을 넣음 */
		middle = n; /* middle에 n을 넣음 */
		n = n->rlink; /* n에 n의 rlink부분을 넣음 */
		middle->rlink = trail; /* middle의 rlink부분에 trail을 넣음 */
		middle->llink = n; /* middle의 llink부분에 n을 넣음 */
	}

	h->rlink = middle; /* h의 rlink부분에 middle을 넣음 */

	return 0; /* 0을 반환함 */
}



/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(listNode* h, int key) { /* 리스트를 검색하여 입력받은 key값보다 큰 값이 나오는 노드 바로 앞에 삽입하는 insertNode 함수 정의 */

	if(h == NULL) return -1; /* h가 NULL이면 -1을 반환함 */

	listNode* node = (listNode*)malloc(sizeof(listNode)); /* listNode크기만큼을 동적할당한 listNode포인터를 listNode포인터 node에 넣음 */
	node->key = key; /* 입력받은 key 값을 node의 key부분에 넣음 */
	node->llink = node->rlink = NULL;  /* node의 llink부분과 node의 rlink부분을 NULL로 만듦 */

	if (h->rlink == h) /* h의 rlink부분이 h라면 */
	{
		insertFirst(h, key); /* insertFirst함수 호출 */
		return 1; /* 1을 반환함 */
	}

	listNode* n = h->rlink; /* listNode포인터 n에 h의 rlink부분을 넣음 */

	/* key를 기준으로 삽입할 위치를 찾는다 */
	while(n != NULL && n != h) { /* n이 NULL이 아니고 h가 아니면 while문 계속 돎 */
		if(n->key >= key) { /* n의 key부분이 key보다 크거나 같으면 */
			/* 첫 노드 앞쪽에 삽입해야할 경우 인지 검사 */
			if(n == h->rlink) { /* n이 h의 rlink부분이면 */
				insertFirst(h, key); /* insertFirst 함수 호출 */
			} else { /* 중간이거나 마지막인 경우 */
				node->rlink = n; /* node의 rlink부분에 n을 넣음 */
				node->llink = n->llink; /* node의 llink부분에 n의 llink부분을 넣음 */
				n->llink->rlink = node; /* n의 llink의 rlink가 가리키는 곳에 node값을 넣음 */
				n->llink = node; /* n의 llink에 node를 넣음 */
			}
			return 0; /* 0을 반환함 */
		}

		n = n->rlink; /* n의 rlink부분을 n에 넣음 */
	}

	/* 마지막 노드까지 찾지 못한 경우, 마지막에 삽입 */
	insertLast(h, key); /* insertLast 함수 호출*/
	return 0; /* 0을 반환함 */
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(listNode* h, int key) { /* list에서 key에 대한 노드를 삭제하는 deleteNode 함수 정의 */

	if (h->rlink == h || h == NULL)  /* h의 rlink부분이 h이거나 h가 빈공간이라면 */
	{
		printf("nothing to delete.\n");  /* print */
		return 0; /* 0을 반환함 */
	}

	listNode* n = h->rlink; /* h의 rlink부분을 listNode포인터 n에 넣음 */

	while(n != NULL && n != h) { /* n이 빈공간이 아니고 h가 아니라면 */
		if(n->key == key) { /* n의 key부분이 key값이라면 */
			if(n == h->rlink) { /* 첫 노드째 노드 인경우 */
				deleteFirst(h); /* deleteFirst함수 호출 */
			} else if (n->rlink == h){ /* 마지막 노드인 경우 */
				deleteLast(h); /* deleteLast함수 호출 */
			} else { /* 중간인 경우 */
				n->llink->rlink = n->rlink; /* n의 llink의 rlink가 가리키는 곳에 n의 rlink를 넣음 */
				n->rlink->llink = n->llink; /* n의 rlink의 llink가 가리키는 곳에 n의 llink를 넣음 */
				free(n); /* n을 해제시킴 */
			}
			return 0; /* 0을 반환함 */
		}

		n = n->rlink; /* n에 n의 rlink부분을 넣음 */
	}

	/* 찾지 못 한경우 */
	printf("cannot find the node for key = %d\n", key); /* print */
	return 0; /* 0을 반환함 */
}