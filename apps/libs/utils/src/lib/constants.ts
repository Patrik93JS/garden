import Koa from 'koa';

export const app = new Koa({ proxy: true });

export const PORT = process.env.PORT || 8000;
