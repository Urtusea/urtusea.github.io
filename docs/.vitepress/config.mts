import { defineConfig } from 'vitepress'
import getArticles from './articles.mts';
import getSidebar from './sidebar.mjs';

let articles = getArticles('src');
const sidebar = getSidebar(articles);

// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "urtusea.github.io",
  description: "my document",
  themeConfig: {
    // https://vitepress.dev/reference/default-theme-config
    nav: [
      { text: '主页', link: '/index.md' },
      { text: 'XCPC-Template', link: '/xcpc-template/index' },
      { text: 'XCPC-Algorithm', link: '/xcpc-algorithm/index' }
    ],

    sidebar,

    // sidebar: [
    //   {
    //     text: 'Examples',
    //     items: [
    //       { text: 'Markdown Examples', link: '/markdown-examples' },
    //       { text: 'Runtime API Examples', link: '/api-examples' }
    //     ]
    //   }
    // ],

    socialLinks: [
      { icon: 'github', link: 'https://github.com/Urtusea/urtusea.github.io/' }
    ]
  }
})
