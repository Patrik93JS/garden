import Router from 'koa-router';
import bodyParser from 'koa-bodyparser';
import { PORT } from '@garden/utils';
import Koa from 'koa';

export const app = new Koa({ proxy: true });

const router = new Router();

app.use(bodyParser());
app.use(router.routes());
app.use(router.allowedMethods());
app.listen(PORT, () => console.log(`listening on http://localhost:${PORT}...`));
