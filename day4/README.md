# Day4 环形缓冲区 + 多线程 + helgrind 死锁排查

## 调试截图
![helgrind](pic/day4_helgrind.png)

## Day4 知识卡片
1. 环形缓冲区：head/tail 模运算，满/空双指针判断  
2. 多线程生产/消费：mutex 保护共享区，0 死锁是底线  
3. helgrind：一键检测竞态 & 死锁，ERROR SUMMARY 必须为 0  
4. 模运算 `% SIZE` 代替 if 判断，代码更简洁  
5. 单元测试：先单线程跑通，再上并发，调试成本减半