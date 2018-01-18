#include "AthmeticYl.h"



AthmeticYl::AthmeticYl()
{
	srand((unsigned)time(NULL)); //ÿ�����н��г�ʼ�� 	
}


AthmeticYl::~AthmeticYl()
{
}

//����һλС��
double AthmeticYl::ro(double r) {
	double a = 10 * r, b;
	b = (a > 0.0) ? floor(a + 0.5) : ceil(a - 0.5);
	return b / 10;
}

//���ز����������ȼ�
int AthmeticYl::Priority(char op) {
	if (op == '+') return 1;
	else if (op == '-') return 1;
	else if (op == 'x') return 2;
	else  return 2;
}
//�����Լ��
int AthmeticYl::gcd(int a, int b)
{
	return a == 0 ? b : gcd(b%a, a);
}
//���ݲ�������������������
struct fraction AthmeticYl::Ca(struct fraction n1, struct fraction n2, char op) {
	struct fraction gb;
	int f;
	switch (op) {
	case '+': {
		gb.a = n1.a*n2.b + n1.b*n2.a;
		gb.b = n1.b*n2.b;
		break;
	}
	case '-': {
		gb.a = n1.a*n2.b - n1.b*n2.a;
		gb.b = n1.b*n2.b;
		break;
	}
	case 'x': {
		gb.a = n1.a*n2.a;
		gb.b = n1.b*n2.b;
		break;
	}
	case '/': {
		gb.a = n1.a*n2.b;
		gb.b = n1.b*n2.a;
		break;
	}
	default: {
		gb.a = 0;
		gb.b = 1;
	}
	}
	f = gcd(gb.a, gb.b);
	gb.a = gb.a / f;
	gb.b = gb.b / f;
	//�����ĸΪ������ȡ��
	if (gb.b<0) {
		gb.a = -gb.a;
		gb.b = -gb.b;
	}
	return gb;
}
//�������1������������ӡ 
struct fraction AthmeticYl::getN()
{
	int i, j, f;
	struct fraction gn;
	if (rand() % 3 == 1)
	{
		i = rand() % 9 + 1;
		j = rand() % 9 + 1;
		f = gcd(j, i);
		i = i / f;
		j = j / f;
		pTest.append(QString::number(i)).append("/").append(QString::number(j));
		cout << i << "/" << j;
		//buf.append(i);
	}
	else {
		i = rand() % 99 + 1;
		j = 1;
		cout << i;
		pTest.append(QString::number(i));
	}
	gn.a = i;
	gn.b = j;
	return gn;
}
//�������һ������������ӡ
char AthmeticYl::getop() {
	char op = ope[rand() % 4];
	if (op == '/')
	{
		cout << "��";
		pTest.append(QString::fromLocal8Bit("��"));
	}
	else if (op == 'x')
	{
		cout << "��";
		pTest.append(QString::fromLocal8Bit("��"));

	}
	else if (op == ope[0]) {
		cout << op;
		pTest.append(QString::fromLocal8Bit("+"));
	}
	else if (op == ope[1]) {
		cout << op;
		pTest.append(QString::fromLocal8Bit("��"));
	}

	return op;
}
char AthmeticYl::m() {
	pTest.clear();//����ǰ�������һ������
	srand((unsigned)time(NULL));      //ÿ�����н��г�ʼ�� 									
	int n, op_N = 0, r_op_N = 0;      //����������Ŀ�ĸ��� 
	double score = 100, times = 0;               //��Ŀ�÷� 
	time_t start, end;
	char k;
	cout << "��������Ŀ����(��������:-n 5,������5����Ŀ)��";
	//cin >> n;
	n = TestN;//��ֵ����
	while (n<1) {
		cout << "��������ȷ�ĳ�����Ŀ��" << endl;
		cin >> n;
	}
	cout << "���ι�" << n << "�⣬����100��,�������������������" << endl;
	//��һ��forѭ����ÿ������һ����Ŀ 
	//for (int j = 0;j<n;j++) {
		PrintTest(0);
		//cout << "��" << j + 1 << "��" << endl;
		//int t = 0, a = 0, b = 0, top = 0;
		//double cost = 0;
		//struct fraction opN[11], numStack[11];
		//char op, operatorStack[20], expQueue[30];
		//opN[a++] = getN();
		//expQueue[b++] = a - 1 + '0';//������ת��Ϊ�ַ��ʹ����ַ������У��Դ˼�¼��������������˳��
		//							//���븽�ӹ��ܣ�����������������
	
		//int op_Num = rand() % 9 + 1;
		//for (t = 0;t<op_Num;t++)
		//{
		//	op = getop();  //���������  			
		//	if (t == 0) {
		//		operatorStack[top++] = op;
		//		opN[a++] = getN();
		//		expQueue[b++] = a - 1 + '0';
		//		continue;        //����ѭ��
		//	}
		//	//������������ȼ����򣬿��Ƴ�ջ˳��
		//	while (Priority(op) <= Priority(operatorStack[top - 1]) && top>0) {
		//		top--;
		//		expQueue[b++] = operatorStack[top];
		//	}
		//	operatorStack[top++] = op;
		//	opN[a++] = getN();//����һ������� 
		//	expQueue[b++] = a - 1 + '0';//������ת��Ϊ�ַ��ʹ����ַ������У���¼����������
		//}
		////��ʣ��ĵ����ȼ�������ȡ������expqueue��
		//while (top>0) {
		//	top--;
		//	expQueue[b++] = operatorStack[top];
		//}
		////���ݺ�׺���ʽ������ 		
		//top = 0;
		//for (int i = 0;i<b;i++) {
		//	if (expQueue[i] >= '0'&&expQueue[i] <= ':')//
		//	{
		//		int ch = expQueue[i] - '0';//��������ַ�ת��Ϊ���͵�������ֵ������Ӧ��������opNum�е�����
		//		numStack[top].a = opN[ch].a;
		//		numStack[top].b = opN[ch].b;
		//		top++;
		//	}
		//	else {
		//		top--;
		//		numStack[top - 1] = Ca(numStack[top - 1], numStack[top], expQueue[i]);
		//	}
		//}
		//cout << "=";
		////�û����������
		//char  rightAns[100], userAns[100];
		////��������numStack�еĽ����ֵ���ַ������У������ж��û��Ĵ��Ƿ���ȷ
		//if (numStack[top - 1].b != 1) {
		//	sprintf_s(rightAns, "%d%s", numStack[top - 1].a, "/");
		//	sprintf_s(rightAns, "%s%d", rightAns, numStack[top - 1].b);
		//}
		//else
		//	sprintf_s(rightAns, "%d", numStack[top - 1].a);

		//time(&start);
		//cin >> userAns;
		//time(&end);
		//cost = difftime(end, start);
		//cout << "������ʱ" << cost << "��" << endl;
		////�ж϶Դ� 
		//if (strcmp(userAns, rightAns) == 0)
		//{
		//	if (cost <= 10 * op_Num) {
		//		r_op_N += op_Num;
		//		cout << "�ش���ȷ��" << endl;
		//	}
		//	else {
		//		cout << "�ش���ȷ���������㱾�����ⳬʱ�����ⲻ����ɼ�" << endl;
		//	}
		//}
		//else {
		//	if (cost >10 * op_Num) {

		//		cout << "���ⳬʱ��" << endl;
		//	}
		//	cout << "����ȷ����ȷ��= " << rightAns << endl;

		//}
		//op_N += op_Num;
		//times += cost;
	//}
	//cout << "���δ�������ʱ" << times << "��" << endl;
	//score = ro(100 * r_op_N / op_N);
	cout << "���ε÷�" << score << endl;
	cout << "���´��������롮y��" << endl;
	//cin >> k;
	return k;
}
void AthmeticYl::PrintTest(int j)
{
	cout << "��" << j + 1 << "��" << endl;
	int t = 0, a = 0, b = 0, top = 0;
	double cost = 0;
	struct fraction opN[11], numStack[11];
	char op, operatorStack[20], expQueue[30];
	opN[a++] = getN();
	expQueue[b++] = a - 1 + '0';//������ת��Ϊ�ַ��ʹ����ַ������У��Դ˼�¼��������������˳��
								//���븽�ӹ��ܣ�����������������
	int op_Num = rand() % 9 + 1;
	for (t = 0;t<op_Num;t++)
	{
		op = getop();			//���������  			
		if (t == 0) {
			operatorStack[top++] = op;
			opN[a++] = getN();
			expQueue[b++] = a - 1 + '0';
			continue;        //����ѭ��
		}
		//������������ȼ����򣬿��Ƴ�ջ˳��
		while (Priority(op) <= Priority(operatorStack[top - 1]) && top>0) {
			top--;
			expQueue[b++] = operatorStack[top];
		}
		operatorStack[top++] = op;
		opN[a++] = getN();//����һ������� 
		expQueue[b++] = a - 1 + '0';//������ת��Ϊ�ַ��ʹ����ַ������У���¼����������
	}
	//��ʣ��ĵ����ȼ�������ȡ������expqueue��
	while (top>0) {
		top--;
		expQueue[b++] = operatorStack[top];
	}


	//���ݺ�׺���ʽ������ 		
	top = 0;
	for (int i = 0;i<b;i++) {
		if (expQueue[i] >= '0'&&expQueue[i] <= ':')//
		{
			int ch = expQueue[i] - '0';//��������ַ�ת��Ϊ���͵�������ֵ������Ӧ��������opNum�е�����
			numStack[top].a = opN[ch].a;
			numStack[top].b = opN[ch].b;
			top++;
		}
		else {
			top--;
			numStack[top - 1] = Ca(numStack[top - 1], numStack[top], expQueue[i]);
		}
	}
	pTest.append("=");
	cout << "=";
	//�û����������
	char   userAns[100];
	//��������numStack�еĽ����ֵ���ַ������У������ж��û��Ĵ��Ƿ���ȷ
	if (numStack[top - 1].b != 1) {
		sprintf_s(mRightAns, "%d%s", numStack[top - 1].a, "/");
		sprintf_s(mRightAns, "%s%d", mRightAns, numStack[top - 1].b);
	}
	else
		sprintf_s(mRightAns, "%d", numStack[top - 1].a);
}
bool AthmeticYl::Jug(QString YouAns)
{
	if (strcmp(YouAns.toLatin1(), mRightAns) == 0)
	{
	
			cout << "�ش���ȷ��" << endl;
			return true;

	}
	else {
		gRightAns.clear();	//�������һ�εĻ���
		gRightAns.append(mRightAns);
		cout << "����ȷ����ȷ��= " << mRightAns << endl;
		return false;


	}
}
//int main()
//{
//	srand((unsigned)time(NULL)); //ÿ�����н��г�ʼ�� 	
//	char kk;
//	do {
//		kk = m();
//		system("cls");
//	} while (kk == 'y');
//	return 0;
//}
