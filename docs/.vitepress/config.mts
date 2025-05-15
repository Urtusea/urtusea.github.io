import { defineConfig } from 'vitepress'

// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "urtusea.github.io",
  description: "my document",
  head : [ ['link', { rel : 'icon', href : '/icon.png' }] ],
  
  themeConfig: {
    // https://vitepress.dev/reference/default-theme-config
    nav: [
      { text: '主页', link: '/' },
      { text: 'XCPC-Template', link: '/xcpc-template/' },
      { text: 'XCPC-Algorithm', link: '/xcpc-algorithm/' }
    ],

    sidebar: {
      '/xcpc-template/': [
        {
          text: 'XCPC-Template',
          items: [
          ]
        }
      ],

      '/xcpc-algorithm/': [
        {
          text: 'XCPC-Algorithm',
          items: [

          ]
        }
      ]
    },

    socialLinks: [
      { icon: 'github', link: 'https://github.com/Urtusea/urtusea.github.io/' }
    ]
  }
})
