# Cpp11WebServer

23.9.27： 解决Epoll与Channel的循环包含
23.10.9:  解决BUG：accept第三个参数需要初始化，否则会返回-1
23.10.11: 增加Server、EventLoop，引入Reactor模式，进一步抽象模型。更改Channel旧接口
23.10.12： 增加Acceptor类，解决编译warnig
// MARK 
成员变量在使用初始化列表初始化时，与构造函数中初始化成员列表的顺序无关，只与定义成员变量的顺序有关。因为成员变量的初始化次序是根据变量在内存中次序有关，而内存中的排列顺序早在编译期就根据变量的定义次序决定了。这点在EffectiveC++中有详细介绍。
2、如果不使用初始化列表初始化，在构造函数内初始化时，此时与成员变量在构造函数中的位置有关

23.10.18： ThreadPoll::Add()中，invoke_result_t会报错，目前只能使用result_of_t
23.10.19: 使用多线程Reactor重构了网络架构
23.10.20: // TODO 服务器whil(true) 改为定时，检查是否正确释放资源
23.10.25： Accept中的socket需要传递客户端的socket //FIXED
23.10.26: Socket析构函数会关闭fd，局部变量的Socket会出错 //Fixed
          //todo reuse_port addr
