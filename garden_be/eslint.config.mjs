import js from "@eslint/js";
import globals from "globals";
import tseslint from "typescript-eslint";
import { defineConfig } from "eslint/config";

export default defineConfig([
	{
		files: ["**/*.{js,mjs,cjs,ts,mts,cts}"],
		plugins: { js },
		extends: ["js/recommended"],
		languageOptions: {
			globals: globals.browser,
		},
	},
	tseslint.configs.recommended,
	{
		env: {
			node: true, // Prostředí Node.js
			es2021: true, // Podpora moderního JavaScriptu (ES12)
		},
		extends: [
			"airbnb-base", // Základní pravidla Airbnb pro čistý kód
			"plugin:node/recommended", // Pravidla pro Node.js
			"plugin:promise/recommended", // Pravidla pro asynchronní kód
		],
		parserOptions: {
			ecmaVersion: 12, // ES2021
			sourceType: "module", // Podpora ES modulů (import/export)
		},
		rules: {
			// Obecná pravidla
			"no-console": "warn", // Povolit console.log, ale s varováním
			"no-unused-vars": [
				"error",
				{
					vars: "all",
					args: "after-used",
					ignoreRestSiblings: true,
				},
			], // Kontrola nepoužitých proměnných
			indent: ["error", 2], // 2 mezery pro odsazení
			quotes: ["error", "single"], // Jednoduché uvozovky
			semi: ["error", "always"], // Vždy vyžadovat středník

			// Node.js specifická pravidla
			"node/no-unsupported-features/es-syntax": [
				"error",
				{ ignores: ["modules"] },
			], // Povolit ES moduly
			"node/no-missing-import": "off", // Vypnout pro ES moduly, pokud nejsou potřeba přípony .js

			// Pravidla pro asynchronní kód (důležité pro Koa)
			"promise/always-return": "error", // Zajistit, že async funkce vždy něco vrací
			"promise/no-return-wrap": "error", // Zabránit zbytečnému obalování v Promise.resolve/reject
			"promise/catch-or-return": "error", // Vyžadovat .catch() nebo return pro Promise

			// Upravená pravidla pro Koa
			"no-param-reassign": [
				"error",
				{ props: false },
			], // Povolit modifikaci ctx v Koa middleware
			"consistent-return": "off", // Vypnout pro Koa, protože middleware nemusí vždy vracet hodnotu
		},
	},
	{
		env: {
			node: true, // Prostředí Node.js
			es2021: true, // Podpora moderního JavaScriptu (ES12)
		},
		parser: "@typescript-eslint/parser", // Parser pro TypeScript
		parserOptions: {
			ecmaVersion: 12, // ES2021
			sourceType: "module", // Podpora ES modulů
			project: "./tsconfig.json", // Odkaz na tsconfig.json pro typovou kontrolu
		},
		plugins: [
			"@typescript-eslint", // Plugin pro TypeScript pravidla
			"node", // Plugin pro Node.js
			"promise", // Plugin pro asynchronní kód
		],
		extends: [
			"airbnb-base", // Základní pravidla Airbnb
			"plugin:node/recommended", // Pravidla pro Node.js
			"plugin:promise/recommended", // Pravidla pro asynchronní kód
			"plugin:@typescript-eslint/recommended", // Doporučená TypeScript pravidla
			"plugin:@typescript-eslint/recommended-requiring-type-checking", // Pravidla vyžadující typovou kontrolu
		],
		rules: {
			// Obecná pravidla
			"no-console": "warn", // Povolit console.log s varováním
			indent: ["error", 2], // 2 mezery pro odsazení
			quotes: ["error", "single"], // Jednoduché uvozovky
			semi: ["error", "always"], // Vždy vyžadovat středník

			// Node.js pravidla
			"node/no-unsupported-features/es-syntax": [
				"error",
				{ ignores: ["modules"] },
			], // Povolit ES moduly
			"node/no-missing-import": "off", // Vypnout pro ES moduly

			// Pravidla pro asynchronní kód
			"promise/always-return": "error", // Async funkce musí vracet hodnotu
			"promise/no-return-wrap": "error", // Zabránit zbytečnému obalování v Promise
			"promise/catch-or-return": "error", // Vyžadovat .catch() nebo return

			// Koa-specifická pravidla
			"no-param-reassign": [
				"error",
				{ props: false },
			], // Povolit modifikaci ctx v Koa
			"consistent-return": "off", // Vypnout pro Koa middleware

			// TypeScript-specifická pravidla
			"@typescript-eslint/no-unused-vars": [
				"error",
				{
					vars: "all",
					args: "after-used",
					ignoreRestSiblings: true,
				},
			], // Nahradí no-unused-vars pro TS
			"@typescript-eslint/explicit-function-return-type":
				"off", // Nepožadovat explicitní návratové typy (pro flexibilitu)
			"@typescript-eslint/no-explicit-any":
				"warn", // Varovat při použití typu any
			"no-use-before-define": "off", // Vypnout, protože TS to řeší lépe
			"@typescript-eslint/no-use-before-define": [
				"error",
				{
					functions: false,
					classes: true,
					variables: true,
				},
			], // TS verze pravidla
			"import/extensions": [
				"error",
				"ignorePackages",
				{ js: "never", ts: "never" },
			], // Nepožadovat přípony .ts/.js
			"import/no-unresolved": "off", // Vypnout, protože TS kontroluje importy
		},
	},
]);
