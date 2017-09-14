#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Config.h"

int main()
{
	// ��һ��д�ļ���ָ�� config.ini �ļ�
	std::string strConfigFileName("config.ini");
	std::ofstream out(strConfigFileName);
	// ��ʼ��д��ע��
	out << "# test for config read and write\n";
	// д��һ�����ü�¼�� name = wangying
	out << "name = wangying\n";
	out.close();

	// ��ʼ�� Config ��
	Config config(strConfigFileName);

	// ��ȡ��ֵ
	std::string strKey = "name";
	std::string strValue;
	strValue = config.Read<std::string>(strKey);
	std::cout << "Read Key " << strKey << "'s Value is " 
		 << strValue << std::endl;

	// д���¼�ֵ��
	std::string strNewKey = "age";
	std::string strNewValue = "23";
	config.Add<std::string>(strNewKey, strNewValue);

	// �� Config ����޸�д���ļ�
	out.open(strConfigFileName, std::ios::app);
	if (out.is_open()) {
		// ���� Config ��� << ���������
		out << config;
		std::cout << "Write config content success!" << std::endl;
	}
	out.close();

	system("pause");
	return 0;
}
