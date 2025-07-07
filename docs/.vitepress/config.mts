import { defineConfig } from 'vitepress'

// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "urtusea.github.io",
  description: "urtusea.github.io",
  head: [
    [
      'link',
      { rel: 'icon', href: '/icon.png' }
    ],
    [
      'link',
      { rel: 'preconnect', href: 'https://fonts.googleapis.com' }
    ],
    [
      'link',
      { rel: 'preconnect', href: 'https://fonts.gstatic.com', crossorigin: '' }
    ],
    [
      'link',
      { href: 'https://fonts.googleapis.com/css2?family=JetBrains+Mono:ital,wght@0,100..800;1,100..800&display=swap', rel: 'stylesheet' }
    ]
  ],

  themeConfig: {
    // https://vitepress.dev/reference/default-theme-config

    nav: [
      { text: '主页', link: '/' },
      { text: '随笔', link: '/note/' },
      { text: 'XCPC-Template', link: '/xcpc-template/' },
      { text: 'XCPC-Algorithm', link: '/xcpc-algorithm/' }
    ],

    sidebar: {
      '/note/' : [
        {
          text: '随笔',
          items: [
            {
              text: 'XCPC-游记',
              collapsed: true,
              items: [
                { text: '2025 CCPC 山东省赛', link: 'note/XCPC/2025-CCPC-shandong' }
              ]
            }
          ]
        }
      ],

      '/xcpc-template/': [
        {
          text: 'XCPC-Template',
          items: [
            {
              text: '前言',
              link: '/xcpc-template/'
            },
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
    ],

    outline: {
      label: '页面导航'
    },
  }
})
