import Koa from "koa";

const app = new Koa();

const server = app.listen(3000, () => {
	console.log("Server is running on port 3000");
});
