#include <iostream>
#include "post.h"

int main() {
    Sender zhang("Zhang Haifan");
    // 收信地址，信件内容等 ·····
	Recipient wang("Wang Huiming");
    Letter letter("信息学院南楼A310", "Happy birthday, Huiming", wang);
    Postman tom("Tom");
    Postman jerry("Jerry");
    PostOffice oucBranch(tom, jerry); // 创建邮局，并登记在此工作的邮递员

    string type = zhang.sendLetter(letter, oucBranch, "surface mail"); // 平邮寄信
    // string type = zhang.sendLetter(letter, oucBranch, "EMS"); // EMS寄信

    double postage = oucBranch.dealService(letter, type); // 邮局办理业务，确定邮费
    zhang.pay(oucBranch, postage); // 寄信者付费
    Postman &postman = oucBranch.assignPostman(type); // 邮局分配邮递员

    postman.deliverLetter(letter); // 邮递员送信

    wang.receiveLetter(letter); // 收信人收到信件

    return 0;
}