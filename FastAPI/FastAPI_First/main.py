from fastapi import FastAPI,Path,Query,HTTPException,Depends
from pydantic import BaseModel,Field
from fastapi.responses import HTMLResponse
from fastapi.responses import FileResponse

# 创建 FastAPI 实例
app = FastAPI()

# 创建依赖项
async def common_parameters(
        skip:int = Query(0,ge = 0,le = 10),
        limit:int = Query(10,le = 60)
):
    return{"skip":skip,"limit":limit}

# 注入依赖项
@app.get("/news/news_list")
async def get_news_list(commons = Depends(common_parameters)):
    return commons

@app.get("/user/user_list")
async def get_user_list(commons = Depends(common_parameters)):
    return commons


@app.get("/")
async def root():
    return{"message":"Hello world"}

if __name__ == "__main__":
    import uvicorn

    uvicorn.run("main:app",host="127.0.0.1",port=8000,reload=True)