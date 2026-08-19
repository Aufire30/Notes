## 学习路径（按顺序）

### 阶段一：Python 基础与现代异步编程（4~6 周 · 大三上 9 月）
- **语法核心**：变量、数据类型、控制流、函数、面向对象（类/继承）、异常处理
- **必会核心库**：
  - 数据与网络：`requests` / `httpx`（异步网络请求）、`json`、`os`、`pathlib`
  - **`pydantic`（必学）**：数据校验与类型定义，大模型结构化输出与参数约束的绝对底座
  - **`asyncio`（必学）**：异步并发编程（Agent 多工具并行调用、流式传输、事件循环核心）
  - **Subprocess / 系统调用**：理解外部命令调用与本地隔离执行基础
- **工程工具**：**Git**（必须熟练分支与提交规范）、VS Code、命令行/Shell 基础
- **练手**：写异步爬虫抓取多页数据、用 Pydantic 校验并处理复杂嵌套 JSON/Excel 文件

> 不需要学 C++/Java，Python 一条路走到黑即可。算法题每天刷 30 分钟，初期别耗在死磕难题上。

---

### 阶段二：LLM 交互、结构化输出与前沿推理范式（2~3 周 · 大三上 10 月）

- **模型原理认知**：Token 机制、上下文窗口（Context Window）、Temperature、Top-p、System/User/Assistant 角色分工
- **推理模型（Reasoning Models）认知**：理解 DeepSeek-R1 / Claude 3.7 / o1 等具备 Extended Thinking（思考链/Thinking Token）的交互特点，以及其与传统 Prompt 的配合差异
- **Prompt Engineering（提示工程）**：Few-Shot（少样本）、Chain-of-Thought（CoT 思维链）、System Prompt 结构化角色约束
- **结构化输出（Structured Outputs）**：掌握基于 JSON Schema / Pydantic 的强制格式化输出（避免大模型输出非标准 JSON）
- **API 与流式交互**：调用真实 API（DeepSeek / OpenAI / Qwen 等），掌握 **Streaming（流式响应 / SSE）** 异步解析
- **Function Calling / Tool Use 底座**：深入理解模型如何识别工具定义、参数提取、本地执行、结果回填再生成的完整闭环
- **Code-as-Action 概念起步**：理解以“生成并执行 Python 代码”替代单步繁琐 JSON 工具调用的高阶动作范式
- 🚀 **【项目一启动 · 10 月中下旬】**：**《轻量级 Agent 内核 + Code-as-Action 沙箱执行器》**（纯 API + Pydantic + 异步 Tool Use + Python 代码沙箱执行 + 异常自省重试，打稳底层机制底座）

---

### 阶段三：Agent 核心知识与前沿架构（4~6 周 · 大三上 11~12 月，重点中的重点）

这是“Agent 岗”和“普通前后端开发”最大的区别，面试必考深度：

1. **认知与决策范式**：
   - **ReAct 循环**（Thought → Action → Observation → Repeat）
   - **Plan-and-Solve / ReWOO**：高层规划与底层执行解耦（DAG 任务图构建与并行执行）
   - **Reflection & Self-Correction**（反思自省机制，如 Reflexion、失败重试与自愈策略）
   - **Code-as-Action 实战**：编写 Python 脚本执行复杂数据清洗与批处理任务，集成基础沙箱（Docker / Subprocess 隔离）
2. **状态图与编排框架（重中之重）**：
   - **LangGraph（必修核心）**：
     - `StateGraph` 状态图定义、条件分支路由、分支并发汇聚（Fan-out / Fan-in）
     - `Checkpointer` 状态持久化（支持任务断点挂起、故障恢复与 Time Travel 状态回溯）
     - `Human-in-the-loop`（人工审批流与人机协同介入机制）
   - **Multi-Agent（多智能体协作）**：Supervisor 集中主管模式、Hierarchical 层次化分工、多 Agent 辩论与共识机制
   - **低代码中台认知**：掌握 Dify / Coze 平台工作流编排、自定义 Tool / 插件扩展与 API 对接
3. **MCP（Model Context Protocol）协议生态**：
   - 深入理解 Anthropic 推出的 MCP 行业事实标准：MCP Client、MCP Server 架构与 JSON-RPC 通信规范
   - 掌握 MCP 核心三要素：**Tools（工具动作）**、**Resources（上下文资源）**、**Prompts（提示词模板）**
   - 实践：手写自定义 MCP Server，打通本地文件系统、数据库与 GitHub 等外部生态
   - 🚀 **【项目二启动 · 11 月中旬】**：**《基于 LangGraph + MCP 的企业级自愈运维/工单 Agent》**（面试核心王牌：LangGraph 状态图 + 人机审批 + MCP 异构工具生态 + Langfuse 链路追踪）
4. **知识增强与上下文工程（Agentic RAG + Context Management）**：
   - **Agentic RAG**：意图自适应路由、Query 递归拆解与多跳检索（Multi-Hop）、混合检索（BM25 + 向量检索 + Cross-Encoder Rerank 精排）、文档级/切片级幻觉校验
   - **上下文工程（Context Engineering）**：Token 爆炸治理、动态结果摘要、Prompt Caching（提示词缓存）命中优化
   - **记忆体系（Memory）**：短期会话上下文滑动窗口/压缩 + 分层持久记忆（Letta/MemGPT 核心记忆、工作记忆与归档存储，Mem0 自主记忆演进）
   - 🚀 **【项目三启动 · 12 月上旬】**：**《工业级 Agentic RAG 垂直领域智能知识库》**（结合阶段四的 FastAPI SSE 流式服务化 + Docker 部署，期末月稳步推进）
5. **环境交互与自动化扩展（前沿亮点）**：
   - 掌握 **Browser-Use / Playwright** 基础：结合 VLM 视觉理解与 DOM 元素定位，实现网页端自主填写、跨系统点击与数据抓取（RPA 2.0 场景）
6. **可观测性与链路追踪（Observability - 企业级必备）**：
   - 熟练掌握 **Langfuse / Phoenix**：Agent 多步调用链路追踪（Trace）、Step-level Token 消耗与延迟分析、Bad Case / 死循环链路排查
7. **Agent 评测与安全（Eval & Safety）**：
   - **评测体系**：基于 LLM-as-a-Judge 的量化评测、**决策轨迹评测（Trajectory / Step-level Eval）**、工具调用精准率与召回率（Ragas / DeepEval）
   - **安全防御**：Prompt 注入防御、工具鉴权与敏感操作审计、代码执行沙箱安全

---

### 阶段四：工程能力补齐与服务化上线（贯穿始终 · 大三上 12 月 ~ 寒假）
- **Web 服务化**：**FastAPI（首选）** 异步框架、RESTful API 设计、**SSE（Server-Sent Events）流式推送**
- **数据与缓存**：PostgreSQL（结合 pgvector 向量扩展）、SQLite、Redis（会话状态暂存、分布式锁与调用限流）
- **容器与部署**：Docker、`docker-compose` 编排、基础 Linux 服务器运维（systemctl、Nginx 反向代理与流式传输配置）
- **前端认知**：能看懂基础 HTML/JS/CSS，理解 Webhook 与前后端流式通信即可，不需要深入写复杂前端

---

## 必须做的四个硬核项目（简历与面试核心壁垒）

投简历前必须有 **3 个主打 + 1 个加分项目**（技术点层层递进），且全部**开源到 GitHub**，配齐架构图、Docker 一键启动、演示 GIF/录屏与 Langfuse 调用链路截图：

1. **项目一：轻量级 Agent 内核 + Code-as-Action 沙箱执行器（打底必做）**
   - **技术栈**：原生 Python + `pydantic` 结构化输出 + `asyncio` 异步并发 + Subprocess/Docker 沙箱 + 自省重试（Self-Correction）
   - **亮点**：不依赖三方框架，手写 Tool Use 循环与参数校验；支持模型自主编写 Python 脚本执行复杂数据处理（Code-as-Action），对比传统 JSON 工具调用的 Token 消耗与执行效率，证明底层机制扎实。
2. **项目二：基于 LangGraph + MCP 的企业级自愈运维/智能工单 Agent（核心主打 · 面试王牌）**
   - **技术栈**：LangGraph（StateGraph 状态图、`Checkpointer` 状态持久化断点续跑、`Human-in-the-loop` 人工审批） + 自定义 MCP Server（挂载 GitHub/数据库/监控告警） + Langfuse 全链路追踪
   - **场景推荐**：企业智能工单流转与高危操作审批 / 服务器告警日志自动诊断与 Patch 修复 / 跨系统 SQL 敏捷分析助手。
3. **项目三：工业级 Agentic RAG 垂直领域智能知识库（高频必考）**
   - **技术栈**：意图自适应路由 + 多跳检索（Multi-Hop） + 混合检索（BM25 + 向量 + Reranker 精排） + 幻觉自检过滤 + FastAPI 异步后端 + **SSE 流式推送** + Docker 容器化
   - **亮点**：解决传统 RAG 召回不准与长文本迷失问题，配合 Ragas 量化评测指标，具备生产级服务化与部署能力。
4. **进阶加分项（项目四）：Deep Research 多智能体深度调研与研报生成系统（杀手锏）**
   - **技术栈**：Supervisor 架构 + LangGraph 子图 + 递归子任务规划（Query 分解） + 多 Agent 并行搜集与多信源交叉验证 + 动态大纲人工确认 + 最终长文报告生成
   - **亮点**：对标 OpenAI Deep Research，展示复杂长链路决策、多智能体协同协作与信息综合提炼的高阶能力。

---

## 时间轴与学习节奏表

### 大三上（2026.9 ~ 2027.1）：打地基 + 前三个项目

| 时间 | 学习内容 | 产出 |
| :--- | :--- | :--- |
| **9 月** | Python 语法速成 + **`asyncio` 异步编程** + **`pydantic` 数据建模** + Git 分支规范 + Linux 基础 | GitHub 保持提交，完成异步并发爬虫与复杂 JSON 数据清洗脚本 |
| **10 月** | 调通 LLM API（DeepSeek/OpenAI/Claude）+ Extended Thinking 交互 + **结构化输出** + **原生 Function Calling 闭环** + **Code-as-Action** | **项目 1：轻量级 Agent 内核与 Code-as-Action 沙箱执行器**（打稳底层机制基础） |
| **11 月** | Agent 核心范式（ReAct/Plan-and-Solve/Reflexion）+ **LangGraph 状态图（StateGraph / checkpointer / human-in-the-loop）** + **MCP 协议（手写自定义 MCP Server）** + **Langfuse 链路追踪** | **项目 2：企业级自愈运维/智能工单 Agent**（LangGraph 状态图 + 人工审批 + MCP 工具生态 + 链路追踪，面试核心主打） |
| **12 月** | **Agentic RAG**（多粒度切分、BM25 + 向量混合检索、Reranker 精排、多跳检索）+ **FastAPI 异步服务化（SSE 流式推送）** + Docker（期末月，节奏放缓） | **项目 3：工业级 Agentic RAG 垂直领域知识库系统**（混合检索+重排、FastAPI+SSE 流式响应、Docker 一键部署） |
| **1 月** | 打磨前 3 个项目（补充高清架构图、Docker 容器化、录制演示 Demo、README 规范化）+ 撰写针对 AI Agent 岗位的 STAR 简历 | 简历初稿 + 3 个高质量 GitHub 作品集 + 在线体验 Demo |

### 寒假（2027.1~2）：冲刺期，改变命运的两个月

- **全职攻克加分杀手锏（项目 4）**：开发 **Deep Research 多智能体深度调研系统**（Supervisor 主管 + 递归任务分解 + 检索研究员 + 信源验证员 + 大纲撰写员，结合 LangGraph 子图 + 人工大纲审核 + 最终研报输出）。
- **八股与深挖攻坚**：系统梳理 Agent 核心八股（LangGraph 内部状态与 Checkpointer 机制、MCP 协议通信规范、Context 爆炸治理、轨迹评测、RAG 调优、Token 成本控制）。
- **整理投递清单与个性化自荐**：列出 50+ 家目标公司（AI 原生创企：智谱、MiniMax、月之暗面、百川、零一万物、面壁、阶跃星辰等；垂直行业 AI 公司；大厂 AI/Agent 业务线），准备自荐信与作品集 Demo 链接。
- **2 月初开始抢跑投递**：不要等 3 月春招拥堵，年前年后就主动出击。

### 大三下（2027.2 ~ 6）：投递 + 面试

- **2~4 月是投递黄金期**：每周精准投递 10~20 家，每场面试务必录音复盘，针对高频追问（尤其是 LangGraph 复杂分支控制、RAG 调优参数、MCP 工具扩展、Token 治理）持续迭代话术。
- **同时留意“日常实习”先行破局**：优先抓中小厂或大厂 AI 组的日常实习（边读书边兼职/远程实习 2~3 个月），提前积累真实生产环境 Agent 运维经验。
- **5 月锁定暑期实习 Offer**：带着真实实习背景与深度项目在暑期实习面试中形成降维打击，6 月准备入职。
- **暑期实习目标：全力转正**：深入企业核心业务，在降低 Token 成本、提升 Agent 执行成功率等指标上出成果，争取 2027 年秋招前直接拿下转正意向书！

---

## 中小厂求职的三个关键策略

**1. 简历只写项目，别写“熟悉 XX”**
每个项目按四要素写：解决什么问题 → 技术栈 → 你的具体实现 → 量化效果（如“多跳问答准确率从 58% 提升至 84%，通过 Prompt Caching 与 CodeAct 降低 45% Token 消耗”）。GitHub 链接放在最显眼位置。

**2. 主动出击，别只挂招聘平台**
BOSS直聘是主力，但中小厂还吃这一套：看到感兴趣的创业公司，直接给创始人/CTO 发邮件或私信，附上你的 GitHub 和项目演示链接。**自荐信 + 演示作品 > 机械海投**。

**3. 开源贡献是隐形加分项**
给 Dify、LangGraph、Browser-Use、Langfuse 或中文文档提几个 PR（哪怕修文档、补单测、修小 bug），面试时一句“我给 XX 项目提过 PR”非常加分，直接证明工程代码素养。

---

## 每周节奏（3~4 小时/天怎么排）

- 周一到周五：每天 2 小时（晚上固定时段：1 小时学新知识/看源码 + 1 小时写代码/刷题）
- 周末：每天 6~8 小时集中攻克难点 + 写项目核心模块
- 大约每周 20 小时，正好匹配计划

---

## 计算机基础与高频八股清单

| 知识块 | 要学吗 | 学到什么程度 | 怎么学 | 什么时候 |
| :--- | :--- | :--- | :--- | :--- |
| **数据结构与算法** | ✅ 必学 | 数组/链表/哈希/栈/队列/二叉树，LeetCode 简单中等 50~100 题 | 每天 30 分钟刷题（重点哈希与字符串处理） | 大三上持续 |
| **Linux 基础** | ✅ 必学 | 常用命令：文件操作、进程、权限、ssh/scp、systemctl、日志排查 | 项目 3/4 部署时实操 | 12月 ~ 寒假 |
| **Docker** | ✅ 必学 | 镜像构建、容器管理、`docker-compose` 多服务编排 | 项目 2/3/4 容器化实操 | 11月 ~ 寒假 |
| **数据库** | ✅ 必学 | SQL 增删改查、索引原理、pgvector 向量插件基本操作 | 课内 + 项目 2/3 实操 | 11月 ~ 12月 |
| **计算机网络** | 了解即可 | HTTP/HTTPS、RESTful、SSE（流式推送原理）、JSON-RPC（MCP 通信） | 项目实战自然接触 | 10月 ~ 11月 |
| **Git** | ✅ 必学 | 分支切换、commit 规范、PR 流程、冲突解决，形成肌肉记忆 | 每天提交 GitHub | 9 月开始 |

### 核心 Agent 深度八股与面试高频考点

1. **编排与框架机制**：
   - LangGraph 的 `StateGraph` 与传统线性链（Sequential Chain）底层有什么本质区别？如何实现分支汇聚（Fan-in / Fan-out）？
   - LangGraph 的 `Checkpointer` 是如何持久化状态的？为什么能支持“断点人工审批，几天后唤醒继续执行（Time Travel）”？
   - 什么时候用单 Agent + 工具，什么时候必须用 Multi-Agent？多智能体带来的延迟与通信开销如何权衡？
2. **协议与通信生态**：
   - 什么是 MCP（Model Context Protocol）？与传统 OpenAPI / Swagger 工具定义相比，MCP 的 Tools、Resources、Prompts 三层架构解决了什么痛点？
   - 客户端与 MCP Server 之间是如何通过 JSON-RPC 通信的？
3. **上下文与性能优化**：
   - Agent 在多轮 Tool Calling 中上下文迅速爆炸（Context Overflow），有哪些治理手段？（动态摘要、滑动窗口、Prompt Caching 命中优化）。
   - 什么是 Code-as-Action？相比传统单步 JSON Function Calling，它在复杂任务中有哪些优势？
4. **稳定性、安全与评测**：
   - 面对模型“幻觉工具调用”（调了不存在的工具或参数类型错误），你的自愈重试机制如何设计？如何防止死循环？
   - 什么是决策轨迹评测（Trajectory Evaluation）？如何用 Langfuse 追踪定位 Agent 的错误决策步？
   - RAG 召回率低、排序靠后、长文本丢失时分别怎么针对性调优？

---

## 岗位搜索关键词

- **核心关键词**：`AI Agent 工程师`、`大模型应用开发工程师`、`智能体开发工程师`、`Agent 后端开发`、`LLM 应用开发`、`RAG 算法/开发工程师`

---

## 找实习实用实战技巧

**1. 深夜 11 点后再刷**
白天在线的大多是按流程走、回复慢的 HR；晚上 11 点后在线的基本是技术小老板或业务骨干，忙完一天亲自捞人。这个时段聊天回复率高、拍板快，聊得好第二天就能直接约面。

**2. 频繁切换通勤地址挖隐藏岗位**
不要死守一个固定区域。换个地址，系统就会按新坐标定向推送一批之前刷不到的岗位——换个坐标等于换个候选池。

**3. 筛选条件这样勾，避开坑公司**
不要只填薪资范围，优先尝试筛选：**不需要融资、规模 20–99 人、成立 3–5 年**。这类公司老板自掏腰包经营，不靠融资续命，业务稳定，基本能避开皮包公司。

**4. 看注册资本 + “创始人”标签**
进公司主页先看注册资本，**100 万以下慎重**；多看招聘者头像旁是否有“创始人/CTO/技术负责人”标签。直接跟技术负责人聊，比和 HR 拉扯管用十倍。

**5. 面试开录音，面一家学一家**
面试时开启录音（供自己复盘复盘），面试结束后把所有追问、答得磕碰的问题全部记下来，整理成专属标准答案。前期把面试当免费实训，面多了你会比面试官更熟练，自信是复盘练出来的。

**6. 每天刷一遍【推荐职位】**
除了手动关键词搜，记得每天看 BOSS 的“推荐职位”，算法按简历匹配的最新释放机会不要让它落灰。