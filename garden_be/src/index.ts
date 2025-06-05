import Koa from "koa";
import Router from "koa-router";
import bodyParser from "koa-bodyparser";

const app = new Koa({ proxy: true });

const PORT = process.env.PORT || 8000;

const router = new Router();

router.get("/", async (ctx) => {
	const name = ctx.query.name || "Tomku";
	ctx.body = {
		message: `Hello, ${name}!`,
	};
});

router.get("/garden", async (ctx) => {
	const name = ctx.query.name || "Tomku";
	ctx.body = {
		message: `Jdem na to, ${name}!`,
	};
});

app
	.use(bodyParser())
	.use(router.routes())
	.use(router.allowedMethods())
	.listen(PORT, () =>
		console.log(
			`listening on http://localhost:${PORT}...`
		)
	);
