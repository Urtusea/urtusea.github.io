import { defineConfig } from 'vitepress'

// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "urtusea.github.io",
  description: "my document",
  head : [
    [
      'link',
      { rel : 'icon', href : '/icon.png' }
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
  // cleanUrls: true,
  
  themeConfig: {
    // https://vitepress.dev/reference/default-theme-config
    nav: [
      { text: '主页', link: '/index.md' },
      { text: 'XCPC-Template', link: '/xcpc-template/' },
      { text: 'XCPC-Algorithm', link: '/xcpc-algorithm/' }
    ],

    sidebar: {
      '/xcpc-template/': [
        {
          text: 'XCPC-Template',
          items: [
            {
              text : '注意事项',
              link : '/xcpc-template/'
            },
            {
              text : '基本模板',
              collapsed : true,
              items : [
                { text : 'ModInt - 模数类', link : '/xcpc-template/base/modint' }
              ]
            }
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
