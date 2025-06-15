import Koa from 'koa';
import Router from 'koa-router';
import bodyParser from 'koa-bodyparser';

const app = new Koa({ proxy: true });

const PORT = process.env.PORT || 8000;

const router = new Router();

app.use(bodyParser());
app.use(router.routes());
app.use(router.allowedMethods());
app.listen(PORT, () => console.log(`listening on http://localhost:${PORT}...`));
