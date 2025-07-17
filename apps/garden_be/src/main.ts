import Router from 'koa-router';
import bodyParser from 'koa-bodyparser';
import { app, PORT } from '@garden/utils';

const router = new Router();

app.use(bodyParser());
app.use(router.routes());
app.use(router.allowedMethods());
app.listen(PORT, () => console.log(`listening on http://localhost:${PORT}...`));
