import { defineConfig } from 'vitepress'

// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "urtusea.github.io",
  description: "",
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
  // cleanUrls: true,

  themeConfig: {
    // https://vitepress.dev/reference/default-theme-config

    nav: [
      { text: '主页', link: '/' },
      { text: '随笔', link: '' },
      { text: 'XCPC-Template', link: '/xcpc-template/' },
      { text: 'XCPC-Algorithm', link: '/xcpc-algorithm/' }
    ],

    sidebar: {
      '/xcpc-template/': [
        {
          text: 'XCPC-Template',
          items: [
            {
              text: '前言',
              link: '/xcpc-template/'
            },
            {
              text: '数据结构',
              collapsed: true,
              items: [
                {
                  text: '线段树',
                  collapsed: true,
                  items: [
                    { text: 'Segment Tree - 单点修改线段树', link: '/xcpc-template/data_structure/segment_tree' },
                    { text: 'Segment Tree Lazy - 区间修改懒标记线段树', link: '/xcpc-template/data_structure/segment_tree_lazy' }
                  ]
                }
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
    ],

    outline: {
      label: '页面导航'
    },
  }
})
