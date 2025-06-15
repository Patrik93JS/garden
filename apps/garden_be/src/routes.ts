import Router from 'koa-router';

const router = new Router();

router.get('/', async (ctx) => {
  const name = ctx.query.name || 'Tomku';
  ctx.body = {
    message: `Hello, ${name}!`,
  };
});

router.get('/garden', async (ctx) => {
  const name = ctx.query.name || 'Tomku';
  ctx.body = {
    message: `Jdem na to, ${name}!`,
  };
});
